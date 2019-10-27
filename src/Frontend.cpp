#include "../olcPixelGameEngine/olcPixelGameEngine.h"
#include <iostream>
// Constants
int amountPixelsX = 240;
int amountPixelsY = 160;
int tileSize = 16;
int playerSpeed = 70;

// The imports need to be in proper order
// clang-format off
olc::PixelGameEngine *context;
#include "Camera/Camera.h"
Camera camera;
#include "Sprite/Sprite.h"
#include "Resources.h"
#include "OverworldEntity/OverworldEntity.h"
#include "Tile/Tile.h"
// clang-format on
class Frontend : public olc::PixelGameEngine {

public:
  Frontend() { sAppName = "Frontend"; }
  Tile tile[50][50];
  OverworldEntity player;
  bool OnUserCreate() override {
    InitializeResources();
    for (int i = 0; i < 50; i++) {
      for (int o = 0; o < 50; o++) {
        tile[i][o] = Tile(grassSprite);
      }
    }
    player.drawCentered = true;
    player.upSprite = playerUpSprite;
    player.downSprite = playerDownSprite;
    player.leftSprite = playerLeftSprite;
    player.rightSprite = playerRightSprite;
    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override {
    Clear(olc::BLACK);
    // int drawnCount = 0;
    for (int i = 0; i < 50; i++) {
      for (int o = 0; o < 50; o++) {
        int xLocation = i * tileSize;
        int yLocation = o * tileSize;
        // Don't draw every tile, only needed ones
        if (camera.isObjectVisible(xLocation, yLocation, tileSize, tileSize)) {
          tile[i][o].Draw(xLocation + camera.x, yLocation + camera.y);
          // drawnCount++;
        }
      }
    }
    // std::cout << "This many tiles have been drawn: " << drawnCount <<
    // std::endl;
    SetPixelMode(olc::Pixel::MASK);
    player.Draw();
    if (GetKey(olc::Key::UP).bHeld) {
      player.y += playerSpeed * fElapsedTime;
      player.direction = OverworldEntity::Direction::UP;
    } else if (GetKey(olc::Key::DOWN).bHeld) {
      player.y -= playerSpeed * fElapsedTime;
      player.direction = OverworldEntity::Direction::DOWN;
    }
    if (GetKey(olc::Key::LEFT).bHeld) {
      player.x += playerSpeed * fElapsedTime;
      player.direction = OverworldEntity::Direction::LEFT;
    } else if (GetKey(olc::Key::RIGHT).bHeld) {
      player.x -= playerSpeed * fElapsedTime;
      player.direction = OverworldEntity::Direction::RIGHT;
    }
    camera.x = player.x;
    camera.y = player.y;
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
