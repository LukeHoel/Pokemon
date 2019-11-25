#ifndef POKEMONSPECIES_H
#define POKEMONSPECIES_H
#include "../Config/Config.h"
#include "../Sprite.h"
#include "Pokedex.h"
#include <string>
#include <vector>
// Keys for pokemon stats
const std::string pokemonSpeciesNameKey = "name";
const std::string pokemonSpeciesHealthPointsKey = "healthpoints";
const std::string pokemonSpeciesPhysicalAttackKey = "physicalattack";
const std::string pokemonSpeciesPhysicalDefenceKey = "physicaldefence";
const std::string pokemonSpeciesSpecialAttackKey = "specialattack";
const std::string pokemonSpeciesSpecialDefenceKey = "specialdefence";
const std::string pokemonSpeciesSpeedKey = "speed";
// Keys for player spritesheet coordinates
const std::string pokemonSpeciesPlayerXKey = "playerx";
const std::string pokemonSpeciesPlayerYKey = "playery";
const std::string pokemonSpeciesPlayerWidthKey = "playerwidth";
const std::string pokemonSpeciesPlayerHeightKey = "playerheight";
// Keys for opposing spritesheet coordinates
const std::string pokemonSpeciesOpposingXKey = "opposingx";
const std::string pokemonSpeciesOpposingYKey = "opposingy";
const std::string pokemonSpeciesOpposingWidthKey = "opposingwidth";
const std::string pokemonSpeciesOpposingHeightKey = "opposingheight";

// Required inputs
std::initializer_list<std::string> pokemonSpeciesRequiredKeys = {
    pokemonSpeciesNameKey,
    pokemonSpeciesPlayerXKey,
    pokemonSpeciesPlayerYKey,
    pokemonSpeciesPlayerWidthKey,
    pokemonSpeciesPlayerHeightKey,
    pokemonSpeciesOpposingXKey,
    pokemonSpeciesOpposingYKey,
    pokemonSpeciesOpposingWidthKey,
    pokemonSpeciesOpposingHeightKey,
    pokemonSpeciesHealthPointsKey,
    pokemonSpeciesPhysicalAttackKey,
    pokemonSpeciesSpecialAttackKey,
    pokemonSpeciesPhysicalDefenceKey,
    pokemonSpeciesSpecialDefenceKey,
    pokemonSpeciesSpeedKey

};
struct PokemonSpecies {
  std::string name;
  // base stats
  int healthPointsBaseStat;
  int physicalAttackBaseStat;
  int specialAttackBaseStat;
  int physicalDefenceBaseStat;
  int specicialDefenceBaseStat;
  int speedBaseStat;
  // Some info
  Sprite *playerBattleSprite;
  Sprite *opposingBattleSprite;
  std::vector<Move *> availableMoves;
    // When created in pokedex
  PokemonSpecies(Config config) {
    if (!config.sectionComplete(pokemonSpeciesRequiredKeys)) {
      throw std::invalid_argument("Invalid pokemon configuration");
    }
    name = config[pokemonSpeciesNameKey];
    healthPointsBaseStat = std::stoi(config[pokemonSpeciesHealthPointsKey]);
    physicalAttackBaseStat = std::stoi(config[pokemonSpeciesPhysicalAttackKey]);
    specialAttackBaseStat = std::stoi(config[pokemonSpeciesSpecialAttackKey]);
    physicalDefenceBaseStat = std::stoi(config[pokemonSpeciesPhysicalDefenceKey]);
    specicialDefenceBaseStat = std::stoi(config[pokemonSpeciesSpecialDefenceKey]);
    speedBaseStat = std::stoi(config[pokemonSpeciesSpeedKey]);

    Sprite *spriteSheet = spriteSheetStore[config["spritesheet"]];
    if (spriteSheet != nullptr) {
      playerBattleSprite =
          spriteSheet->getPartial(std::stoi(config[pokemonSpeciesPlayerXKey]),
                                  std::stoi(config[pokemonSpeciesPlayerYKey]),
                                  std::stoi(config[pokemonSpeciesPlayerWidthKey]),
                                  std::stoi(config[pokemonSpeciesPlayerHeightKey]));
      opposingBattleSprite =
          spriteSheet->getPartial(std::stoi(config[pokemonSpeciesOpposingXKey]),
                                  std::stoi(config[pokemonSpeciesOpposingYKey]),
                                  std::stoi(config[pokemonSpeciesOpposingWidthKey]),
                                  std::stoi(config[pokemonSpeciesOpposingHeightKey]));
    }
    // Get the available moveset
    for (std::string moveName : config.keys("availablemoves")) {
      if (pokedex.availableMoves.find(moveName) !=
          pokedex.availableMoves.end()) {
        availableMoves.push_back(pokedex.availableMoves[moveName]);
      }
    }
  }
};
#endif