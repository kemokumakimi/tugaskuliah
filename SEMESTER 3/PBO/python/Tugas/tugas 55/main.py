import requests
from bs4 import BeautifulSoup

response = requests.get('https://id.wikipedia.org/wiki/Bruce_Lee')
if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
    teks = soup.find(class_='mw-headline').text
    if teks == 'Kehidupan awal' or 'kehidupan awal':
        print("Teks : ", teks)
    else:
        print("Teks tidak ditemukan")
else:
    print("Gagal mengambil konten")