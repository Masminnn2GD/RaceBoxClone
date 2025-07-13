#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "ui.h"
#include "gps.h"
#include "imu.h"
#include "drag.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int menuIndex = 0;
const int menuCount = 3;

String menuLabels[] = {"Home", "Lap Timer", "Drag Race"};

void initUI() {
  Wire.begin(MPU_SDA, MPU_SCL);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);
}

void showLoadingScreen() {
  display.clearDisplay();

  // Logo placeholder (sederhana)
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 10);
  display.println("RaceBox");

  display.setTextSize(1);
  display.setCursor(30, 35);
  display.println("Clone v1.0");

  display.setCursor(25, 50);
  display.print("Loading");
  display.display();

  for (int i = 0; i < 3; i++) {
    delay(400);
    display.print(".");
    display.display();
  }

  delay(800);
}

void handleButtons() {
  static unsigned long lastPress = 0;
  if (millis() - lastPress < 200) return;

  if (digitalRead(BTN_UP) == LOW) {
    menuIndex = (menuIndex - 1 + menuCount) % menuCount;
    lastPress = millis();
  }
  if (digitalRead(BTN_DOWN) == LOW) {
    menuIndex = (menuIndex + 1) % menuCount;
    lastPress = millis();
  }
  if (digitalRead(BTN_SELECT) == LOW) {
    if (menuIndex == 2) startDragRace();  // Masuk drag race
    lastPress = millis();
  }
}

void updateUI() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("RaceBox Clone");

  switch (menuIndex) {
    case 0: { // Home
      display.setCursor(0, 15);
      display.print("Speed: ");
      display.print(getSpeed(), 1);
      display.println(" km/h");

      display.print("GX: ");
      display.print(getGX(), 2);
      display.print("  GY: ");
      display.println(getGY(), 2);
      break;
    }
    case 1: { // Lap Timer
      display.set
