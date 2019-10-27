#ifndef battle_h
#define battle_h
#include "../GameLogic/Pokemon.h"

int infoWidth = 100;
int healthBarWidth = infoWidth - 2;
int infoHeight = 30;
int textAreaHeight = 50;

void drawPokemonInfo(int x, int y, Pokemon pokemon) {
  // White background
  context->FillRect(x, y, infoWidth, infoHeight, olc::WHITE);
  // Grey background to bar
  context->FillRect(x + 1, y + 1, healthBarWidth, 3, olc::DARK_GREY);
  // Health bar (show as percentage of max)
  if (pokemon.HP > 0 && pokemon.maxHP > 0) {
    context->FillRect(x + 1, y + 1,
                      healthBarWidth * (pokemon.HP / pokemon.maxHP), 3,
                      olc::DARK_GREEN);
  }
}
void drawBattle(float deltaTime) {
  // Draw battle stages
  battleStageSprite->Draw(amountPixelsX - 20 - battleStageSprite->width(), 40);
  battleStageSprite->Draw(20, amountPixelsY - battleStageSprite->height() - 40);
  // Info area for each pokemon
  drawPokemonInfo(amountPixelsX - infoWidth,
                  amountPixelsY - textAreaHeight - infoHeight,
                  playerCurrentPokemon);
  drawPokemonInfo(0, 0, opposingCurrentPokemon);
  // Text area
  context->FillRect(0, amountPixelsY - textAreaHeight, amountPixelsX,
                    textAreaHeight, olc::DARK_BLUE);
}
#endif