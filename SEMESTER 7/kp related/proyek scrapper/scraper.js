// Import library yang dibutuhkan
const express = require('express');
const cors = require('cors');
const puppeteer = require('puppeteer');

// Inisialisasi server Express
const app = express();
const PORT = 3000;

// Gunakan CORS agar frontend bisa mengakses API ini
app.use(cors());

// --- FUNGSI-FUNGSI SCRAPER ---

function parseSocialCount(text) {
    if (!text) return 0;
    const lowerCaseText = text.toLowerCase().trim();
    let num = parseFloat(lowerCaseText.replace(/,/g, ''));
    if (lowerCaseText.includes('m')) {
        num *= 1000000;
    } else if (lowerCaseText.includes('k')) {
        num *= 1000;
    }
    return Math.round(num);
}

async function scrapeTikTokData(username) {
    if (!username) return { platform: 'TikTok', username: '', followers: 0, likes: 0 };
    console.log(`[TikTok] Memulai scraping untuk: @${username}`);
    const browser = await puppeteer.launch({ headless: true });
    const page = await browser.newPage();
    try {
        await page.goto(`https://www.tiktok.com/@${username}`, { waitUntil: 'networkidle2' });
        const followerSelector = "[data-e2e='followers-count']";
        const likeSelector = "[data-e2e='likes-count']";
        await page.waitForSelector(followerSelector, { timeout: 10000 });
        await page.waitForSelector(likeSelector, { timeout: 10000 });
        const followersText = await page.$eval(followerSelector, (el) => el.textContent);
        const likesText = await page.$eval(likeSelector, (el) => el.textContent);
        console.log(`[TikTok] @${username} | Followers: ${followersText}, Likes: ${likesText}`);
        return {
            platform: 'TikTok',
            username: `@${username}`,
            followers: parseSocialCount(followersText),
            likes: parseSocialCount(likesText),
        };
    } catch (error) {
        console.error(`[TikTok] Gagal scrape @${username}:`, error.message);
        return { platform: 'TikTok', username: `@${username}`, followers: 0, likes: 0 };
    } finally {
        await browser.close();
    }
}

async function scrapeInstagramData(username) {
    if (!username) return { platform: 'Instagram', username: '', followers: 0 };
    console.log(`[Instagram] Mengembalikan data simulasi untuk @${username}`);
    return {
        platform: 'Instagram',
        username: `@${username}`,
        followers: Math.floor(Math.random() * 90000) + 10000,
    };
}

async function scrapeXData(username) {
    if (!username) return { platform: 'X (Twitter)', username: '', followers: 0 };
    console.log(`[X] Mengembalikan data simulasi untuk @${username}`);
    return {
        platform: 'X (Twitter)',
        username: `@${username}`,
        followers: Math.floor(Math.random() * 50000) + 5000,
    };
}

// --- API ENDPOINT ---
app.get('/scrape', async (req, res) => {
    const { instagram, x, tiktok } = req.query;
    console.log('Menerima permintaan scrape untuk:', { instagram, x, tiktok });

    try {
        const [instagramData, xData, tiktokData] = await Promise.all([
            scrapeInstagramData(instagram),
            scrapeXData(x),
            scrapeTikTokData(tiktok)
        ]);
        res.json({ instagramData, xData, tiktokData });
    } catch (error) {
        console.error("Terjadi error pada server:", error);
        res.status(500).json({ error: 'Gagal melakukan scraping.' });
    }
});

// --- MENJALANKAN SERVER ---
app.listen(PORT, () => {
    console.log(`🚀 Server scraper berjalan di http://localhost:${PORT}`);
    console.log(`   Frontend dapat memanggil API melalui endpoint /scrape`);
});
