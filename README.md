# Arsip Tugas Kuliah

Kumpulan tugas kuliah semester 1 sampai 8, ditampilkan lewat file explorer web
(`index.html`) yang menjelajah isi repository ini melalui GitHub REST API.

## Struktur

```
index.html            File explorer (MyDrive)
SEMESTER 1/ ...       Tugas semester 1
SEMESTER 2/ ...       Tugas semester 2
...
SEMESTER 8/ ...       Tugas semester 8
```

## Cara pakai file explorer

Buka `index.html` di browser. Kredensial repository sudah terisi di
`index.html` (`USERNAME` = `kemokumakimi`, `REPO` = `tugaskuliah`).
Klik folder untuk masuk, klik file untuk melihat tautan GitHub atau mengunduhnya.

## Batasan

- Repository ini hanya bisa menampilkan file dari repo publik lewat GitHub API
  tanpa token, dengan batas 60 request per jam per IP.
- Dua file tidak ikut diunggah karena melebihi batas 100 MB GitHub:
  `SEMESTER 1/BIOLOGI/3d.pptx` dan video export 131 MB di `SEMESTER 5/`.
