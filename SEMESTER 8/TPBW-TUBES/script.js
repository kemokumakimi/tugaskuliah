var map = L.map('map', { zoomControl: false }).setView([-6.9300, 107.6191], 12);

var tileDark = L.tileLayer('https://{s}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}{r}.png', {
    attribution: '© OpenStreetMap © CARTO',
    maxZoom: 19
});

var tileLight = L.tileLayer('https://{s}.basemaps.cartocdn.com/rastertiles/voyager/{z}/{x}/{y}{r}.png', {
    attribution: '© OpenStreetMap © CARTO',
    maxZoom: 19
});

tileDark.addTo(map);

L.control.zoom({ position: 'bottomright' }).addTo(map);

var markers = L.markerClusterGroup({
    chunkedLoading: true,
    iconCreateFunction: function(cluster) {
        var count = cluster.getChildCount();
        return new L.DivIcon({
            html: '<div><span>' + count + '</span></div>',
            className: 'marker-cluster marker-cluster-medium',
            iconSize: new L.Point(40, 40)
        });
    }
});

var heatLayer;
var allStores    = [];
var filteredStores = [];
var userLocation = null;
var currentReviewStoreId = null;
var selectedStarRating   = 0;

function getFavorites() {
    try { return JSON.parse(localStorage.getItem('gymmap_favs') || '{}'); } catch { return {}; }
}

function saveFavorites(obj) {
    localStorage.setItem('gymmap_favs', JSON.stringify(obj));
}

function getReviews() {
    try { return JSON.parse(localStorage.getItem('gymmap_reviews') || '{}'); } catch { return {}; }
}

function saveReviews(obj) {
    localStorage.setItem('gymmap_reviews', JSON.stringify(obj));
}

function isOpenNow(hoursStr) {
    if (!hoursStr) return null; 
    try {
        var now   = new Date();
        var day   = now.getDay(); 
        var hhmm  = now.getHours() * 60 + now.getMinutes();

        var dayMap = { Mo: 1, Tu: 2, We: 3, Th: 4, Fr: 5, Sa: 6, Su: 0 };
        var parts = hoursStr.split(';');
        
        for (var p of parts) {
            p = p.trim();
            var m = p.match(/^([A-Za-z]{2})(?:-([A-Za-z]{2}))?\s+(\d{1,2}):(\d{2})-(\d{1,2}):(\d{2})$/);
            if (!m) continue;

            var startDay = dayMap[m[1]];
            var endDay   = m[2] ? dayMap[m[2]] : startDay;
            var openMin  = parseInt(m[3]) * 60 + parseInt(m[4]);
            var closeMin = parseInt(m[5]) * 60 + parseInt(m[6]);

            var inDayRange;
            if (startDay <= endDay) {
                inDayRange = (day >= startDay && day <= endDay);
            } else {
                inDayRange = (day >= startDay || day <= endDay);
            }

            if (inDayRange && hhmm >= openMin && hhmm < closeMin) return true;
        }
        return false;
    } catch (e) {
        return null;
    }
}

function storeId(store) {
    return (store.name + '|' + store.lat.toFixed(5)).replace(/\s/g, '_');
}

function makeIcon(store) {
    var open = isOpenNow(store.opening_hours);
    
    var pinColor = '#a3a3a3'; 
    if (open === true) pinColor = '#22c55e'; 
    if (open === false) pinColor = '#ef4444'; 

    var svgIcon = `
    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 36" width="36" height="54">
        <path fill="${pinColor}" stroke="#ffffff" stroke-width="2" d="M12 0C5.373 0 0 5.373 0 12c0 8.542 12 24 12 24s12-15.458 12-24C24 5.373 18.627 0 12 0zm0 17c-2.761 0-5-2.239-5-5s2.239-5 5-5 5 2.239 5 5-2.239 5-5 5z"/>
    </svg>`;

    return L.divIcon({
        className: 'custom-svg-pin',
        html: svgIcon,
        iconSize:   [36, 54], 
        iconAnchor: [18, 54], 
        popupAnchor:[0, -50]  
    });
}

function buildPopup(store) {
    var id      = storeId(store);
    var favs    = getFavorites();
    var isFav   = !!favs[id];
    var open    = isOpenNow(store.opening_hours);
    var reviews = getReviews()[id] || [];

    var statusHtml = '';
    if (open === true)       statusHtml = '<span class="popup-status open">● Buka Sekarang</span>';
    else if (open === false) statusHtml = '<span class="popup-status closed">● Tutup</span>';
    else                     statusHtml = '<span class="popup-status unknown">● Jam tidak diketahui</span>';

    var hoursHtml   = store.opening_hours ? `🕐 ${store.opening_hours}<br>` : '';
    var phoneHtml   = store.phone && store.phone.trim()
        ? `📞 <a href="tel:${store.phone}">${store.phone}</a><br>` : '';
    var ratingHtml  = store.rating
        ? `⭐ ${store.rating}${store.reviews ? ` (${store.reviews} ulasan)` : ''}<br>` : '';
    var srcIcon     = store.source === 'Google Maps' ? '[G]' : '[O]';

    var reviewSnippet = '';
    if (reviews.length > 0) {
        var last = reviews[reviews.length - 1];
        var stars = '★'.repeat(last.rating) + '☆'.repeat(5 - last.rating);
        reviewSnippet = `<div style="margin-top:8px;padding:6px;background:var(--bg3);border-radius:8px;font-size:10px;">
            <span style="color:var(--text)">${stars}</span>
            <span style="color:var(--text2);margin-left:4px">"${last.text}"</span>
        </div>`;
    }

    var dirUrl = `https://www.google.com/maps/dir/?api=1&destination=${store.lat},${store.lng}`;

    return `<div class="store-popup">
        <h4>${store.name}</h4>
        <p class="popup-addr">📍 ${store.address || '-'}</p>
        ${statusHtml}
        <div class="popup-meta">
            ${ratingHtml}${hoursHtml}${phoneHtml}
            <span style="font-size:10px;color:var(--text2)">${srcIcon} ${store.source}</span>
        </div>
        ${reviewSnippet}
        <div class="popup-actions">
            <a href="${dirUrl}" target="_blank" class="popup-btn">🗺️ Arahkan</a>
            <button class="popup-btn ${isFav ? 'fav-active' : ''}"
                onclick="toggleFav('${id}','${store.name.replace(/'/g,"\\'")}',${store.lat},${store.lng})"
                id="favbtn-${id}">
                ${isFav ? '★ Tersimpan' : '☆ Favorit'}
            </button>
            <button class="popup-btn"
                onclick="openReview('${id}','${store.name.replace(/'/g,"\\'")}')">
                💬 Review
            </button>
        </div>
    </div>`;
}

function renderToMap(data) {
    markers.clearLayers();
    if (heatLayer) map.removeLayer(heatLayer);

    var heatPoints = [];

    data.forEach(store => {
        heatPoints.push([store.lat, store.lng, 1]);
        var marker = L.marker([store.lat, store.lng], { icon: makeIcon(store) });
        marker.bindPopup(buildPopup(store), { maxWidth: 300 });
        markers.addLayer(marker);
    });

    map.addLayer(markers);

    heatLayer = L.heatLayer(heatPoints, {
        radius: 28, blur: 18, maxZoom: 15,
        gradient: { 0.4: '#3b82f6', 0.65: '#f97316', 1: '#ef4444' }
    }).addTo(map);

    updateStats(data);
}

function updateStats(data) {
    var openCount = data.filter(s => isOpenNow(s.opening_hours) === true).length;

    document.getElementById('totalBadge').textContent = data.length + ' gym';
    document.getElementById('statTotal').textContent = data.length;
    document.getElementById('statOpen').textContent  = openCount;
}

function applyFilters() {
    var city      = document.getElementById('cityFilter').value.toLowerCase();
    var openOnly  = document.getElementById('openNowFilter').checked;
    var searchVal = document.getElementById('searchInput').value.toLowerCase();

    filteredStores = allStores.filter(s => {
        var matchCity = city === 'all' ||
            (s.address && s.address.toLowerCase().includes(city)) ||
            (s.name && s.name.toLowerCase().includes(city));
            
        var matchOpen = !openOnly || isOpenNow(s.opening_hours) === true;
        var matchSearch = !searchVal || (s.name && s.name.toLowerCase().includes(searchVal));

        return matchCity && matchOpen && matchSearch;
    });

    renderToMap(filteredStores);

    if (searchVal) {
        document.getElementById('searchClear').style.display = 'block';
        document.getElementById('searchResults').innerHTML = filteredStores.length > 0 
            ? filteredStores.map(s => `
                <div class="search-result-item" onclick="zoomToStore(${s.lat}, ${s.lng})">
                    <div class="search-result-name">${s.name}</div>
                    <div class="search-result-addr">${s.address}</div>
                </div>`).join('')
            : '<div class="search-no-result">Gym tidak ditemukan di area ini</div>';
    } else {
        document.getElementById('searchClear').style.display = 'none';
        document.getElementById('searchResults').innerHTML = '';
    }
}

function loadGeoJSON(url, source) {
    return fetch(url)
        .then(r => r.json())
        .then(data => {
            var added = 0;
            data.features.forEach(f => {
                if (!f.geometry) return;
                var g = f.geometry, p = f.properties;
                var lat, lng;

                if (g.type === 'Point') {
                    lng = g.coordinates[0]; lat = g.coordinates[1];
                } else if (g.type === 'Polygon') {
                    var ring = g.coordinates[0];
                    lat = ring.reduce((s,c) => s + c[1], 0) / ring.length;
                    lng = ring.reduce((s,c) => s + c[0], 0) / ring.length;
                } else return;

                if (lat < -8.0 || lat > -5.5 || lng < 105.0 || lng > 109.5) return;

                allStores.push({
                    lat, lng,
                    name:         p.name  || p.Title || 'Gym / Fitness',
                    address:      p.address || p.Address || [p['addr:street'], p['addr:city']].filter(Boolean).join(', ') || '-',
                    rating:       p.rating  || p['Review Rating'] || null,
                    reviews:      p.reviews || p['# of Reviews'] || null,
                    phone:        p.phone   || p.Phone || p['Phone number'] || null,
                    opening_hours: p.opening_hours || null,
                    website:      p.website || p.Website || null,
                    google_maps:  p.google_maps || p['Google Map URL'] || null,
                    source
                });
                added++;
            });
            console.log(`[${source}] +${added}`);
        })
        .catch(e => console.warn('GeoJSON load error:', url, e));
}

function toggleFav(id, name, lat, lng) {
    var favs = getFavorites();
    if (favs[id]) {
        delete favs[id];
    } else {
        favs[id] = { name, lat, lng };
    }
    saveFavorites(favs);
    renderFavList();

    var btn = document.getElementById('favbtn-' + id);
    if (btn) {
        var isFav = !!favs[id];
        btn.textContent = isFav ? '★ Tersimpan' : '☆ Favorit';
        btn.classList.toggle('fav-active', isFav);
    }
}

function renderFavList() {
    var favs  = getFavorites();
    var keys  = Object.keys(favs);
    var list  = document.getElementById('favList');
    var count = document.getElementById('favCount');
    var clearBtn = document.getElementById('clearFavBtn');

    count.textContent = keys.length;
    clearBtn.style.display = keys.length > 0 ? 'block' : 'none';

    if (keys.length === 0) {
        list.innerHTML = '<p class="hint-text">Klik ⭐ di popup untuk menyimpan.</p>';
        return;
    }

    list.innerHTML = keys.map(id => {
        var f = favs[id];
        return `<div class="fav-item" onclick="map.setView([${f.lat},${f.lng}],16)">
            <span class="fav-item-name">⭐ ${f.name}</span>
            <button class="fav-remove" onclick="event.stopPropagation();toggleFav('${id}','${f.name.replace(/'/g,"\\'")}',${f.lat},${f.lng})">✕</button>
        </div>`;
    }).join('');
}

document.getElementById('clearFavBtn').addEventListener('click', () => {
    localStorage.removeItem('gymmap_favs');
    renderFavList();
});

function openReview(id, name) {
    currentReviewStoreId = id;
    selectedStarRating   = 0;
    document.getElementById('reviewStoreName').textContent = name;
    document.getElementById('reviewText').value = '';
    updateStarUI(0);
    renderExistingReviews(id);
    document.getElementById('reviewModal').classList.add('active');
    map.closePopup();
}

function updateStarUI(val) {
    document.querySelectorAll('#starPicker span').forEach(s => {
        s.classList.toggle('active', parseInt(s.dataset.val) <= val);
    });
}

document.querySelectorAll('#starPicker span').forEach(s => {
    s.addEventListener('click', () => {
        selectedStarRating = parseInt(s.dataset.val);
        updateStarUI(selectedStarRating);
    });
});

function renderExistingReviews(id) {
    var all   = getReviews()[id] || [];
    var box   = document.getElementById('existingReviews');
    if (all.length === 0) { box.innerHTML = ''; return; }
    box.innerHTML = '<p class="section-label" style="margin:14px 0 8px">REVIEW SEBELUMNYA</p>' +
        all.slice().reverse().map(r => `
        <div class="review-card">
            <div class="review-stars">${'★'.repeat(r.rating)}${'☆'.repeat(5-r.rating)}</div>
            <div class="review-body">${r.text}</div>
            <div class="review-date">${r.date}</div>
        </div>`).join('');
}

document.getElementById('submitReview').addEventListener('click', () => {
    var text = document.getElementById('reviewText').value.trim();
    if (!text) { alert('Tulis komentar dulu ya!'); return; }
    if (!selectedStarRating) { alert('Pilih rating bintang dulu!'); return; }

    var all   = getReviews();
    if (!all[currentReviewStoreId]) all[currentReviewStoreId] = [];
    all[currentReviewStoreId].push({
        rating: selectedStarRating,
        text:   text,
        date:   new Date().toLocaleDateString('id-ID', { day:'numeric', month:'short', year:'numeric' })
    });
    saveReviews(all);
    document.getElementById('reviewText').value = '';
    selectedStarRating = 0;
    updateStarUI(0);
    renderExistingReviews(currentReviewStoreId);
    renderToMap(filteredStores);
});

document.getElementById('closeReview').addEventListener('click', () => {
    document.getElementById('reviewModal').classList.remove('active');
});

document.getElementById('reviewModal').addEventListener('click', e => {
    if (e.target === document.getElementById('reviewModal'))
        document.getElementById('reviewModal').classList.remove('active');
});

var isDark = true;
document.getElementById('darkToggle').textContent = '☀️'; 

document.getElementById('darkToggle').addEventListener('click', () => {
    isDark = !isDark;
    document.documentElement.setAttribute('data-theme', isDark ? 'dark' : 'light');
    document.getElementById('darkToggle').textContent = isDark ? '☀️' : '🌙';
    if (isDark) {
        map.removeLayer(tileLight);
        tileDark.addTo(map);
    } else {
        map.removeLayer(tileDark);
        tileLight.addTo(map);
    }
});

document.getElementById('locateBtn').addEventListener('click', () => {
    if (!navigator.geolocation) { alert('Browser kamu tidak support GPS.'); return; }
    document.getElementById('locateBtn').textContent = '⏳';
    navigator.geolocation.getCurrentPosition(pos => {
        userLocation = { lat: pos.coords.latitude, lng: pos.coords.longitude };
        map.setView([userLocation.lat, userLocation.lng], 15);

        L.circleMarker([userLocation.lat, userLocation.lng], {
            radius: 10, color: '#3b82f6', fillColor: '#3b82f6', fillOpacity: 0.4, weight: 2
        }).addTo(map).bindPopup('📍 Lokasi Kamu').openPopup();

        document.getElementById('locateBtn').textContent = '📍';
        document.getElementById('gpsStatus').textContent = '✅ GPS aktif. Bisa sort by jarak.';
    }, () => {
        document.getElementById('locateBtn').textContent = '📍';
        alert('Gagal mendapatkan lokasi. Izinkan akses GPS di browser.');
    });
});

document.getElementById('sortDistBtn').addEventListener('click', () => {
    if (!userLocation) {
        document.getElementById('gpsStatus').textContent = '⚠️ Klik 📍 dulu untuk aktifkan GPS.';
        return;
    }

    function dist(a, b) {
        var R = 6371, dLat = (b.lat - a.lat) * Math.PI/180,
            dLng = (b.lng - a.lng) * Math.PI/180,
            x = Math.sin(dLat/2)**2 + Math.cos(a.lat*Math.PI/180)*Math.cos(b.lat*Math.PI/180)*Math.sin(dLng/2)**2;
        return R * 2 * Math.atan2(Math.sqrt(x), Math.sqrt(1-x));
    }

    filteredStores.sort((a, b) =>
        dist(userLocation, a) - dist(userLocation, b)
    );

    var nearest = filteredStores[0];
    if (nearest) {
        var d = dist(userLocation, nearest);
        document.getElementById('gpsStatus').textContent =
            `Gym terdekat: ${nearest.name} (~${d < 1 ? (d*1000).toFixed(0)+'m' : d.toFixed(1)+'km'})`;
    }

    renderToMap(filteredStores);
});

const searchInput = document.getElementById('searchInput');
const searchResults = document.getElementById('searchResults');
const searchClear = document.getElementById('searchClear');

searchInput.addEventListener('input', () => {
    applyFilters(); 
});

searchClear.addEventListener('click', () => {
    searchInput.value = '';
    applyFilters();
});

function zoomToStore(lat, lng) {
    map.setView([lat, lng], 17);
    if(window.innerWidth <= 640) {
        document.getElementById('sidebar').classList.remove('open');
    }
}

document.getElementById('cityFilter').addEventListener('change', applyFilters);
document.getElementById('openNowFilter').addEventListener('change', applyFilters);

document.getElementById('sidebarToggle').addEventListener('click', () => {
    document.getElementById('sidebar').classList.toggle('open');
});

window.onload = function () {
    document.getElementById('totalBadge').textContent = 'Loading...';

    Promise.all([
        loadGeoJSON('gym_bandung.geojson',       'OpenStreetMap'),
        loadGeoJSON('gym_bandung_gmaps.geojson',  'Google Maps')
    ]).then(() => {
        filteredStores = [...allStores];
        renderToMap(filteredStores);
        renderFavList();
        console.log('✅ Total stores loaded:', allStores.length);
    });
};

document.getElementById('openStatsBtn').addEventListener('click', () => {
    document.getElementById('statsModal').classList.add('active');
    document.getElementById('kpiTotal').textContent = filteredStores.length;
    document.getElementById('kpiOpen').textContent = filteredStores.filter(s => isOpenNow(s.opening_hours) === true).length;
});
document.getElementById('closeStats').addEventListener('click', () => {
    document.getElementById('statsModal').classList.remove('active');
});
/* ============================================================
   HANDLE REDIRECT FROM LANDING PAGE
   Baca hash #lat=...&lng=...&zoom=... lalu fly ke titik tsb
============================================================ */
(function handleHashNavigation() {
  const hash = window.location.hash;
  if (!hash || !hash.includes('lat=')) return;

  const params = {};
  hash.replace('#', '').split('&').forEach(pair => {
    const [k, v] = pair.split('=');
    params[k] = parseFloat(v);
  });

  if (params.lat && params.lng) {
    const tryFly = setInterval(() => {
      if (map && allStores.length > 0) {
        clearInterval(tryFly);
        map.flyTo([params.lat, params.lng], params.zoom || 17, { animate: true, duration: 1.2 });
        history.replaceState(null, '', window.location.pathname);
      }
    }, 200);
    setTimeout(() => clearInterval(tryFly), 5000);
  }
})();