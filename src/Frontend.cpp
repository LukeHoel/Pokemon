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
enum Mode { OVERWORLD, BATTLE };
Mode mode = OVERWORLD;
#include "Sprite.h"
#include "Animation.h"
#include "Resources.h"
#include "Overworld/Tile.h"
#include "Overworld/Overworld.h"
// clang-format on
class Frontend : public olc::PixelGameEngine {

public:
  Frontend() { sAppName = "Frontend"; }
  bool OnUserCreate() override {
    InitializeResources();
    for (int i = 0; i < 50; i++) {
      for (int o = 0; o < 50; o++) {
        tiles[i][o] = Tile(grassSprite);
      }
    }
    player.drawCentered = true;
    player.upSprite = playerUpSprite;
    player.downSprite = playerDownSprite;
    player.leftSprite = playerLeftSprite;
    player.rightSprite = playerRightSprite;
    return true;
  }

  void drawBattle(float deltaTime) {
    // Draw battle stages
    battleStageSprite->Draw(amountPixelsX - 20 - battleStageSprite->width(),
                            40);
    battleStageSprite->Draw(20,
                            amountPixelsY - battleStageSprite->height() - 40);
    // Info area for pokemon (to be replaced with parameters later)
    context->FillRect(0, 0, 100, 40, olc::WHITE);
    context->FillRect(amountPixelsX - 100, amountPixelsY - 90, 100, 40,
                      olc::WHITE);
    // Text area
    context->FillRect(0, amountPixelsY - 50, amountPixelsX, 50, olc::DARK_BLUE);
  }

  bool OnUserUpdate(float deltaTime) override {
    Clear(olc::BLACK);
    switch (mode) {
    case (Mode::OVERWORLD):
      drawOverworld(deltaTime);
      break;
    case (Mode::BATTLE):
      drawBattle(deltaTime);
      break;
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
