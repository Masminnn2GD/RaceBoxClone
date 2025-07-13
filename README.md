# RaceBoxClone

✅ FITUR UTAMA YANG SUDAH DICOVER
| Fitur                         | Status |
| ----------------------------- | ------ |
| OLED UI navigasi (4 tombol)   | ✅      |
| Loading screen dengan logo    | ✅      |
| GPS Speed & Lap Timer         | ✅      |
| G-force dari MPU6050          | ✅      |
| Kalibrasi manual G-force      | ✅      |
| Drag Mode (0–60 / 0–100 km/h) | ✅      |
| microSD logging               | ✅      |
| Penyimpanan per tanggal       | ✅      |

📁 STRUKTUR PROYEK
RaceBoxClone/
├── src/
│   ├── RaceBoxClone.ino        ← main loop
│   ├── config.h                ← pin & setting
│   ├── ui.h / ui.cpp           ← menu, OLED, tombol, logo
│   ├── gps.h / gps.cpp         ← speed, GPS lock
│   ├── imu.h / imu.cpp         ← G-force, kalibrasi
│   ├── drag.h / drag.cpp       ← drag race logic
│   ├── sdlogger.h / sdlogger.cpp ← CSV logging ke folder
├── README.md
├── platformio.ini (opsional)

📦 LIBRARY YANG DIPERLUKAN
| Library            | Fungsi              |
| ------------------ | ------------------- |
| `TinyGPSPlus`      | Parsing data GPS    |
| `MPU6050`          | Baca sensor G-force |
| `Adafruit SSD1306` | Tampilan OLED       |
| `Adafruit GFX`     | Gambar & teks OLED  |
| `SD`               | Akses microSD (SPI) |

💾 LOGGING FORMAT (Contoh isi log.csv)
Time,Speed,GX,GY,0-60,0-100
08:15:21,43.2,0.03,-0.01,0.00,0.00
08:15:22,52.1,0.05,-0.02,0.00,0.00
08:15:24,63.4,0.12,-0.03,3.87,0.00
08:15:27,100.1,0.21,-0.06,3.87,6.25
