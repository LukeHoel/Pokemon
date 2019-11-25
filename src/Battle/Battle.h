#ifndef battle_h
#define battle_h
#include "../GameLogic/Pokemon.h"
#include "../GameLogic/Trainer.h"
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

Trainer *opposingTrainer;

void Run() { mode = Mode::OVERWORLD; }

void Fight() {
  playerFightMenu.active = true;
  battleMainMenu.Reset();
}

void Back() {
  battleMainMenu.active = true;
  playerFightMenu.Reset();
}

void constructMovesMenu(Pokemon *playerPokemon, Pokemon *opposingPokemon) {
  std::vector<MenuItem> moves;

  for (Move *move : playerPokemon->species.availableMoves) {
    auto function = [move, playerPokemon, opposingPokemon](void) {
      playerPokemon->attack(*opposingPokemon, *move);
    };
    MenuItem item;
    item.displayName = move->name;
    item.onSelect = function;
    moves.push_back({move->name, function});
  }
  moves.push_back({"BACK", Back});
  playerFightMenu = Menu(&fireRedBattleEffectFont, moves);
}

// Contruct the menus based on the users
void StartBattle(Config config) {
  opposingTrainer = new Trainer(config);
  mode = Mode::BATTLE;
  battleMainMenu = Menu(&fireRedBattleEffectFont,
                        {{"FIGHT", Fight}, {"BAG"}, {"POKEMON"}, {"RUN", Run}});
  battleMainMenu.active = true;
  constructMovesMenu(&playerTrainer.team.members[0],
                     &opposingTrainer->team.members[0]);
}
void drawPokemonInfo(int x, int y, Pokemon &pokemon) {
  // White background
  context->FillRect(x, y, infoWidth, infoHeight, olc::WHITE);
  DrawSpriteString(pokemon.species.name, x + 1, y + 1, fireRedBattleEffectFont);
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
                  playerTrainer.team.members[0]);
  drawPokemonInfo(0, 0, opposingTrainer->team.members[0]);
  //  Draw pokemon sprites
  playerTrainer.team.members[0].species.playerBattleSprite->Draw(
      playerPokemonBaseX -
          playerTrainer.team.members[0].species.playerBattleSprite->width() /
              2,
      playerPokemonBaseY -
          playerTrainer.team.members[0].species.playerBattleSprite->height());
  opposingTrainer->team.members[0].species.opposingBattleSprite->Draw(
      opposingPokemonBaseX - opposingTrainer->team.members[0]
                                     .species.opposingBattleSprite->width() /
                                 2,
      opposingPokemonBaseY - opposingTrainer->team.members[0]
                                 .species.opposingBattleSprite->height());
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