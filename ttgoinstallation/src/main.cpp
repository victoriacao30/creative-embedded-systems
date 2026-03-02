#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

int frameCount = 0;
bool showText = false;

bool windowLit[4][6];
uint16_t windowColor[4][6];

uint16_t randomWindowColor() {
  int r = random(4);
  if (r == 0) return tft.color565(255, 220, 100);
  if (r == 1) return tft.color565(150, 200, 255);
  if (r == 2) return tft.color565(255, 150, 180);
  return tft.color565(200, 255, 180);
}

void drawBuilding() {
  tft.fillScreen(tft.color565(10, 10, 30));
  tft.fillRect(0, 115, 240, 20, tft.color565(20, 20, 40));
  tft.fillRect(10, 30, 60, 90, tft.color565(40, 40, 55));
  tft.fillRect(85, 15, 70, 105, tft.color565(35, 35, 50));
  tft.fillRect(168, 40, 60, 80, tft.color565(40, 40, 55));
}

void drawWindows() {
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 3; col++) {
      int x = 15 + col * 18;
      int y = 38 + row * 20;
      if (windowLit[row][col])
        tft.fillRect(x, y, 10, 12, windowColor[row][col]);
      else
        tft.fillRect(x, y, 10, 12, tft.color565(20, 20, 35));
    }
  }
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 3; col++) {
      int x = 90 + col * 20;
      int y = 25 + row * 22;
      if (windowLit[row][col+3])
        tft.fillRect(x, y, 12, 14, windowColor[row][col+3]);
      else
        tft.fillRect(x, y, 12, 14, tft.color565(20, 20, 35));
    }
  }
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 2; col++) {
      int x = 175 + col * 22;
      int y = 48 + row * 18;
      if (windowLit[row][col])
        tft.fillRect(x, y, 12, 12, windowColor[row][col]);
      else
        tft.fillRect(x, y, 12, 12, tft.color565(20, 20, 35));
    }
  }
}

void showTextScreen() {
  tft.fillScreen(tft.color565(10, 10, 30));
  tft.setTextColor(tft.color565(180, 180, 220));
  tft.setTextSize(2);
  tft.setCursor(18, 30);
  tft.print("Every window tells");
  tft.setCursor(30, 60);
  tft.print("a different");
  tft.setCursor(55, 90);
  tft.print("story. ");
}

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  randomSeed(millis());

  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 6; c++) {
      windowLit[r][c] = false;
      windowColor[r][c] = randomWindowColor();
    }

  drawBuilding();
  drawWindows();
}

void loop() {
  if (!showText) {
    // building screen - flicker windows for 5 seconds (50 frames)
    if (frameCount % 20 == 0) {
      int r = random(4);
      int c = random(6);
      windowLit[r][c] = !windowLit[r][c];
      if (windowLit[r][c]) windowColor[r][c] = randomWindowColor();
      drawWindows();
    }

    if (frameCount >= 50) {
      showText = true;
      frameCount = 0;
      showTextScreen();
    }

  } else {
    // text screen - hold for 3 seconds (30 frames) then switch back
    if (frameCount >= 30) {
      showText = false;
      frameCount = 0;
      drawBuilding();
      drawWindows();
    }
  }

  frameCount++;
  delay(100);
}
