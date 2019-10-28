#ifndef battle_h
#define battle_h
#include "../GameLogic/Pokemon.h"

int infoWidth = 100;
int healthBarWidth = infoWidth - 2;
int infoHeight = 20;
int textAreaHeight = 48;

void drawPokemonInfo(int x, int y, Pokemon pokemon) {
  // White background
  context->FillRect(x, y, infoWidth, infoHeight, olc::WHITE);
  DrawSpriteString(pokemon.name, x+1,y+1, fireRedBattleEffectFont);
  // Grey background to bar
  context->FillRect(x + 1, y + 10, healthBarWidth, 3, olc::DARK_GREY);
  // Health bar (show as percentage of max)
  if (pokemon.HP > 0 && pokemon.maxHP > 0) {
    context->FillRect(x + 1, y + 10,
                      healthBarWidth * (pokemon.HP / pokemon.maxHP), 3,
                      olc::DARK_GREEN);
  }
}
void drawBattle(float deltaTime) {
  // Draw battle stages
  grassBattleBackgroundSprite->Draw(0, 0);
  // Info area for each pokemon
  drawPokemonInfo(amountPixelsX - infoWidth,
                  amountPixelsY - textAreaHeight - infoHeight,
                  playerCurrentPokemon);
  drawPokemonInfo(0, 0, opposingCurrentPokemon);
  // Text area

  context->FillRect(0, amountPixelsY - textAreaHeight, amountPixelsX - 1,
                    textAreaHeight - 1, olc::GREY);
  context->DrawRect(0, amountPixelsY - textAreaHeight, amountPixelsX - 1,
                    textAreaHeight - 1, olc::DARK_GREY);
}
#endif