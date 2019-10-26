#include "../olcPixelGameEngine/olcPixelGameEngine.h"
#include <iostream>
// Constants
int amountPixelsX = 240;
int amountPixelsY = 160;
int tileSize = 16;

olc::PixelGameEngine *context;
#include "Camera/Camera.h"
Camera camera;
#include "Sprite/Sprite.h"
#include "Tile/Tile.h"

#include "Resources.h"

class Frontend : public olc::PixelGameEngine {

public:
  Frontend() { sAppName = "Frontend"; }
  Tile tile[50][50];
  bool OnUserCreate() override {
    InitializeResources();
    for (int i = 0; i < 50; i++) {
      for (int o = 0; o < 50; o++) {
        tile[i][o] = Tile(placeholder);
      }
    }
    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override {
    Clear(olc::BLACK);
    int drawnCount = 0;
    for (int i = 0; i < 50; i++) {
      for (int o = 0; o < 50; o++) {
        int xLocation = i * tileSize;
        int yLocation = o * tileSize;
        // Don't draw every tile, only needed ones
        if (camera.isObjectVisible(xLocation, yLocation, tileSize, tileSize)) {
          tile[i][o].Draw(xLocation + camera.x, yLocation + camera.y);
          // DrawRect(xLocation + camera.x, yLocation + camera.y, tileSize,
          //          tileSize);
          drawnCount++;
        }
      }
    }
    std::cout << "This many tiles have been drawn: " << drawnCount << std::endl;
    if (GetKey(olc::Key::UP).bHeld) {
      camera.y -= 100 * fElapsedTime;
    } else if (GetKey(olc::Key::DOWN).bHeld) {
      camera.y += 100 * fElapsedTime;
    }
    if (GetKey(olc::Key::LEFT).bHeld) {
      camera.x -= 100 * fElapsedTime;
    } else if (GetKey(olc::Key::RIGHT).bHeld) {
      camera.x += 100 * fElapsedTime;
    }
    return true;
  }
};

int main() {
  context = new Frontend();
  if (context->Construct(amountPixelsX, amountPixelsY, 4, 4)) {
    context->Start();
  }
  return 0;
}
