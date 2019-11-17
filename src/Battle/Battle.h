#ifndef battle_h
#define battle_h
#include "../GameLogic/Pokemon.h"
#include "../Menu.h"

int infoWidth = 100;
int healthBarWidth = infoWidth - 2;
int infoHeight = 20;
int textAreaHeight = 48;
int playerPokemonBaseX = 50;
int playerPokemonBaseY = amountPixelsY - textAreaHeight;
int opposingPokemonBaseX = amountPixelsX - 60;
int opposingPokemonBaseY = 65;
Menu battleMainMenu;
Menu playerFightMenu;

void Run() { mode = Mode::OVERWORLD; }

void Fight() {
  playerFightMenu.active = true;
  battleMainMenu.Reset();
}

void Back() {
  battleMainMenu.active = true;
  playerFightMenu.Reset();
}

void StartBattle() {
  mode = Mode::BATTLE;
  battleMainMenu = Menu(&fireRedBattleEffectFont,
                        {{"FIGHT", Fight}, {"BAG"}, {"POKEMON"}, {"RUN", Run}});
  battleMainMenu.active = true;
  std::vector<MenuItem> moves;

  for (Move *move : playerCurrentPokemon.availableMoves) {
    auto function = [move](void) {
      playerCurrentPokemon.attack(opposingCurrentPokemon, *move);
    };
    MenuItem item;
    item.displayName = move->name;
    item.onSelect = function;
    moves.push_back({move->name, function});
  }
  moves.push_back({"BACK", Back});
  playerFightMenu = Menu(&fireRedBattleEffectFont, moves);
}
void drawPokemonInfo(int x, int y, Pokemon pokemon) {
  // White background
  context->FillRect(x, y, infoWidth, infoHeight, olc::WHITE);
  DrawSpriteString(pokemon.name, x + 1, y + 1, fireRedBattleEffectFont);
  DrawSpriteString(std::to_string(pokemon.level), x + infoWidth - 20, y + 1,
                   fireRedBattleEffectFont);
  // Grey background to bar
  context->FillRect(x + 1, y + 10, healthBarWidth, 3, olc::DARK_GREY);
  // Health bar (show as percentage of max)
  context->FillRect(x + 1, y + 10,
                    healthBarWidth * (pokemon.HP / pokemon.maxHP()), 3,
                    olc::DARK_GREEN);
}
void drawBattle(float deltaTime) {
  // Draw battle stages
  grassBattleBackgroundSprite->Draw(0, 0);
  // Info area for each pokemon
  drawPokemonInfo(amountPixelsX - infoWidth,
                  amountPixelsY - textAreaHeight - infoHeight,
                  playerCurrentPokemon);
  drawPokemonInfo(0, 0, opposingCurrentPokemon);
  // Draw pokemon sprites
  playerCurrentPokemon.playerBattleSprite->Draw(
      playerPokemonBaseX - playerCurrentPokemon.playerBattleSprite->width() / 2,
      playerPokemonBaseY - playerCurrentPokemon.playerBattleSprite->height());
  opposingCurrentPokemon.opposingBattleSprite->Draw(
      opposingPokemonBaseX -
          opposingCurrentPokemon.opposingBattleSprite->width() / 2,
      opposingPokemonBaseY -
          opposingCurrentPokemon.opposingBattleSprite->height());
  // Text area
  context->FillRect(0, amountPixelsY - textAreaHeight, amountPixelsX - 1,
                    textAreaHeight - 1, olc::GREY);
  context->DrawRect(0, amountPixelsY - textAreaHeight, amountPixelsX - 1,
                    textAreaHeight - 1, olc::DARK_GREY);
  if (battleMainMenu.active) {
    battleMainMenu.Draw(amountPixelsX - 40, amountPixelsY - textAreaHeight + 5);
  } else if (playerFightMenu.active) {
    playerFightMenu.Draw(amountPixelsX - 40, amountPixelsY - textAreaHeight + 2,
                         9);
  }
}
#endif