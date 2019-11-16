#ifndef pokemon_h
#define pokemon_h
#include "../Config/Config.h"
#include "../Sprite.h"
#include "Pokedex.h"
#include <string>
// Keys for player spritesheet coordinates
const std::string playerXKey = "playerx";
const std::string playerYKey = "playery";
const std::string playerWidthKey = "playerwidth";
const std::string playerHeightKey = "playerheight";
// Keys for opposing spritesheet coordinates
const std::string opposingXKey = "opposingx";
const std::string opposingYKey = "opposingy";
const std::string opposingWidthKey = "opposingwidth";
const std::string opposingHeightKey = "opposingheight";
struct Pokemon {
  // When created in pokedex
  Pokemon(Config config) {
    name = config["name"];
    Sprite *spriteSheet =
        spriteSheetStore[config["spritesheet"]];
    if (spriteSheet != nullptr) {
      playerBattleSprite = spriteSheet->getPartial(
          std::stoi(config[playerXKey]), std::stoi(config[playerYKey]),
          std::stoi(config[playerWidthKey]),
          std::stoi(config[playerHeightKey]));
      opposingBattleSprite = spriteSheet->getPartial(
          std::stoi(config[opposingXKey]), std::stoi(config[opposingYKey]),
          std::stoi(config[opposingWidthKey]),
          std::stoi(config[opposingHeightKey]));
    }
  }
  Pokemon(std::string name) {
    // Make sure the pokemon name is valid
    if (pokedex.availablePokemon.find(name) != pokedex.availablePokemon.end()) {
      // The base configuration for this type of pokemon
      Pokemon config = *pokedex.availablePokemon[name];
      this->name = config.name;
      playerBattleSprite = config.playerBattleSprite;
      opposingBattleSprite = config.opposingBattleSprite;
    }
  }
  // For the config
  std::string name;
  Sprite *playerBattleSprite;
  Sprite *opposingBattleSprite;
  // For an instance of a pokemon
  float maxHP = 0;
  float HP = 0;
};
// Placeholders for battles
Pokemon playerCurrentPokemon("");
Pokemon opposingCurrentPokemon("");
#endif