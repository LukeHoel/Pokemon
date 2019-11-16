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
#include "Resources/Resources.h"
#include "Overworld/Tile.h"
#include "Overworld/Overworld.h"
#include "Battle/Battle.h"
// clang-format on
class Frontend : public olc::PixelGameEngine {

public:
  Frontend() { sAppName = "Frontend"; }
  bool OnUserCreate() override {
    LoadResources();
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
    // Register the current pokemon
    playerCurrentPokemon = Pokemon("bulbasaur");
    playerCurrentPokemon.maxHP = 100;
    playerCurrentPokemon.HP = 70;
    opposingCurrentPokemon = Pokemon("squirtle");
    opposingCurrentPokemon.maxHP = 20;
    opposingCurrentPokemon.HP = 10;
    return true;
  }

  bool OnUserUpdate(float deltaTime) override {
    Clear(olc::BLACK);
    switch (mode) {
    case (Mode::OVERWORLD):
      drawOverworld(deltaTime);
      DrawSpriteString("ABCDEFGHIJKLMNOPQRSTUVWXYZ.,", 1, 30, fireRedBattleEffectFont);
      break;
    case (Mode::BATTLE):
      drawBattle(deltaTime);
      getBattleInput();
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
