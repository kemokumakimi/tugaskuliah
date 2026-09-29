#!/bin/bash
echo "Mereset USB Controller untuk membebaskan Kinect..."
# Mendapatkan bus USB Kinect
BUS=$(lsusb | grep "Microsoft Corp. Xbox NUI Camera" | awk '{print $2}')
DEVICE=$(lsusb | grep "Microsoft Corp. Xbox NUI Camera" | awk '{print $4}' | sed 's/://')

if [ -z "$BUS" ]; then
    echo "Kinect tidak ditemukan. Cek kabel power."
    exit 1
fi

echo "Me-reset Perangkat USB di Bus $BUS Device $DEVICE..."
# Menggunakan usbreset (jika tersedia)
if command -v usbreset &> /dev/null; then
    sudo usbreset /dev/bus/usb/$BUS/$DEVICE
else
    echo "Tolong install usbreset dengan: sudo apt-get install usbutils"
fi
echo "Selesai. Coba jalankan skrip Python lagi."
