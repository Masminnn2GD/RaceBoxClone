#ifndef CONFIG_H
#define CONFIG_H

// OLED I2C (SSD1306)
#define OLED_ADDR 0x3C

// Tombol (gunakan INPUT_PULLUP)
#define BTN_UP     15
#define BTN_DOWN   2
#define BTN_SELECT 4
#define BTN_BACK   16

// SD Card (SPI)
#define SD_CS      5

// GPS (Serial2 di ESP32)
#define GPS_RX     17
#define GPS_TX     18
#define GPS_BAUD   9600

// MPU6050 (I2C, default SDA/SCL ESP32 = 21, 22)
#define MPU_SDA    21
#define MPU_SCL    22

// Threshold Deteksi Drag (dalam km/h)
#define DRAG_0_60_KMH    60
#define DRAG_0_100_KMH   100

// Kalibrasi awal G-force (bisa diubah via menu)
#define DEFAULT_GX_OFFSET  0.00
#define DEFAULT_GY_OFFSET  0.00

// Logging interval (ms)
#define LOG_INTERVAL_MS   500

#endif
