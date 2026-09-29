"""
fetch_gym_jabar.py
==================
Ambil data gym / fitness center di Jawa Barat dari OpenStreetMap
via Overpass API, lalu simpan sebagai gym_bandung.geojson

Cara pakai:
  pip install requests
  python fetch_gym_jabar.py

Output:
  gym_bandung.geojson  ← taruh di folder yang sama dengan maps.html
"""

import json
import time
import requests

# ─────────────────────────────────────────
# OVERPASS QUERY
# Ambil semua node/way/relation di Jawa Barat
# dengan tag leisure=fitness_centre atau sport=gym
# ─────────────────────────────────────────
OVERPASS_URL = "https://overpass-api.de/api/interpreter"

QUERY = """
[out:json][timeout:60];
area["name"="Jawa Barat"]["admin_level"="4"]->.jabar;
(
  node["leisure"="fitness_centre"](area.jabar);
  way["leisure"="fitness_centre"](area.jabar);
  node["sport"="gym"](area.jabar);
  way["sport"="gym"](area.jabar);
  node["leisure"="sports_centre"]["sport"="fitness"](area.jabar);
  way["leisure"="sports_centre"]["sport"="fitness"](area.jabar);
);
out center tags;
"""

# ─────────────────────────────────────────
# FETCH
# ─────────────────────────────────────────
def fetch_overpass(query, retries=3):
    for attempt in range(1, retries + 1):
        print(f"[{attempt}/{retries}] Menghubungi Overpass API...")
        try:
            resp = requests.post(
                OVERPASS_URL,
                data={"data": query},
                timeout=90,
                headers={"User-Agent": "GymMapBandung/1.0 (tugas WebGIS Telkom University)"}
            )
            resp.raise_for_status()
            return resp.json()
        except requests.RequestException as e:
            print(f"  ⚠ Error: {e}")
            if attempt < retries:
                print(f"  Coba lagi dalam 5 detik...")
                time.sleep(5)
    raise RuntimeError("Gagal fetch data dari Overpass API setelah beberapa percobaan.")


# ─────────────────────────────────────────
# CONVERT → GEOJSON
# ─────────────────────────────────────────
def osm_to_geojson(osm_data):
    features = []

    for el in osm_data.get("elements", []):
        tags = el.get("tags", {})

        # Koordinat: node langsung, way pakai center
        if el["type"] == "node":
            lat = el.get("lat")
            lng = el.get("lon")
        elif el["type"] == "way" and "center" in el:
            lat = el["center"]["lat"]
            lng = el["center"]["lon"]
        else:
            continue

        if lat is None or lng is None:
            continue

        # Ambil field yang relevan
        name    = tags.get("name") or tags.get("name:id") or "Gym / Fitness"
        address = build_address(tags)
        phone   = tags.get("phone") or tags.get("contact:phone") or tags.get("contact:mobile") or None
        website = tags.get("website") or tags.get("contact:website") or None
        opening = tags.get("opening_hours") or None
        sport   = tags.get("sport") or tags.get("leisure") or None

        features.append({
            "type": "Feature",
            "geometry": {
                "type": "Point",
                "coordinates": [lng, lat]
            },
            "properties": {
                "name":          name,
                "address":       address,
                "phone":         phone,
                "website":       website,
                "opening_hours": opening,
                "sport":         sport,
                "rating":        None,
                "reviews":       None,
                "google_maps":   f"https://www.google.com/maps/search/?api=1&query={lat},{lng}",
                "source":        "OpenStreetMap",
                "osm_id":        el.get("id"),
                "osm_type":      el["type"]
            }
        })

    return {
        "type": "FeatureCollection",
        "features": features
    }


def build_address(tags):
    parts = []
    street  = tags.get("addr:street")
    housenr = tags.get("addr:housenumber")
    city    = tags.get("addr:city")
    district= tags.get("addr:district") or tags.get("addr:subdistrict")
    postcode= tags.get("addr:postcode")

    if street:
        parts.append(street + (f" No.{housenr}" if housenr else ""))
    if district:
        parts.append(district)
    if city:
        parts.append(city)
    if postcode:
        parts.append(postcode)

    return ", ".join(parts) if parts else tags.get("description", "-")


# ─────────────────────────────────────────
# MAIN
# ─────────────────────────────────────────
if __name__ == "__main__":
    print("=" * 50)
    print("  GymMap Jawa Barat — Overpass Fetcher")
    print("  Telkom University · WebGIS 2026")
    print("=" * 50)

    raw      = fetch_overpass(QUERY)
    total    = len(raw.get("elements", []))
    print(f"\n✅ Data diterima: {total} elemen dari OSM")

    geojson  = osm_to_geojson(raw)
    count    = len(geojson["features"])
    print(f"✅ Berhasil dikonversi: {count} fitur GeoJSON")

    output   = "gym_bandung.geojson"
    with open(output, "w", encoding="utf-8") as f:
        json.dump(geojson, f, ensure_ascii=False, indent=2)

    print(f"\n📁 Tersimpan → {output}")
    print(f"   Taruh file ini di folder yang sama dengan maps.html\n")

    # Preview 3 data pertama
    print("─── Preview 3 Data Pertama ───")
    for feat in geojson["features"][:3]:
        p = feat["properties"]
        print(f"  📍 {p['name']}")
        print(f"     Alamat : {p['address']}")
        print(f"     Telp   : {p['phone'] or '-'}")
        print(f"     Jam    : {p['opening_hours'] or '-'}")
        print()