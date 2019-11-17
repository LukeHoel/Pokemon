#ifndef pokemon_h
#define pokemon_h
#include "../Config/Config.h"
#include "../Sprite.h"
#include "Pokedex.h"
#include <string>
// Keys for pokemon stats
const std::string pokemonNameKey = "name";
const std::string pokemonHealthPointsKey = "healthpoints";
const std::string pokemonPhysicalAttackKey = "physicalattack";
const std::string pokemonPhysicalDefenceKey = "physicaldefence";
const std::string pokemonSpecialAttackKey = "specialattack";
const std::string pokemonSpecialDefenceKey = "specialdefence";
const std::string pokemonSpeedKey = "speed";
// Keys for player spritesheet coordinates
const std::string pokemonPlayerXKey = "playerx";
const std::string pokemonPlayerYKey = "playery";
const std::string pokemonPlayerWidthKey = "playerwidth";
const std::string pokemonPlayerHeightKey = "playerheight";
// Keys for opposing spritesheet coordinates
const std::string pokemonOpposingXKey = "opposingx";
const std::string pokemonOpposingYKey = "opposingy";
const std::string pokemonOpposingWidthKey = "opposingwidth";
const std::string pokemonOpposingHeightKey = "opposingheight";
// Required inputs
std::initializer_list<std::string> pokemonRequiredKeys = {
    pokemonNameKey,
    pokemonPlayerXKey,
    pokemonPlayerYKey,
    pokemonPlayerWidthKey,
    pokemonPlayerHeightKey,
    pokemonOpposingXKey,
    pokemonOpposingYKey,
    pokemonOpposingWidthKey,
    pokemonOpposingHeightKey,
    pokemonHealthPointsKey,
    pokemonPhysicalAttackKey,
    pokemonSpecialAttackKey,
    pokemonPhysicalDefenceKey,
    pokemonSpecialDefenceKey,
    pokemonSpeedKey

};
struct Pokemon {
  // When created in pokedex
  Pokemon(Config config) {
    if (!config.sectionComplete(pokemonRequiredKeys)) {
      throw std::invalid_argument("Invalid pokemon configuration");
    }
    name = config[pokemonNameKey];
    healthPointsBaseStat = std::stoi(config[pokemonHealthPointsKey]);
    physicalAttackBaseStat = std::stoi(config[pokemonPhysicalAttackKey]);
    specialAttackBaseStat = std::stoi(config[pokemonSpecialAttackKey]);
    physicalDefenceBaseStat = std::stoi(config[pokemonPhysicalDefenceKey]);
    specicialDefenceBaseStat = std::stoi(config[pokemonSpecialDefenceKey]);
    speedBaseStat = std::stoi(config[pokemonSpeedKey]);

    Sprite *spriteSheet = spriteSheetStore[config["spritesheet"]];
    if (spriteSheet != nullptr) {
      playerBattleSprite =
          spriteSheet->getPartial(std::stoi(config[pokemonPlayerXKey]),
                                  std::stoi(config[pokemonPlayerYKey]),
                                  std::stoi(config[pokemonPlayerWidthKey]),
                                  std::stoi(config[pokemonPlayerHeightKey]));
      opposingBattleSprite =
          spriteSheet->getPartial(std::stoi(config[pokemonOpposingXKey]),
                                  std::stoi(config[pokemonOpposingYKey]),
                                  std::stoi(config[pokemonOpposingWidthKey]),
                                  std::stoi(config[pokemonOpposingHeightKey]));
    }
    // Get the available moveset
    for (std::string moveName : config.keys("availablemoves")) {
      if (pokedex.availableMoves.find(moveName) !=
          pokedex.availableMoves.end()) {
        availableMoves.push_back(pokedex.availableMoves[moveName]);
      }
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
      availableMoves = config.availableMoves;
      healthPointsBaseStat = config.healthPointsBaseStat;
      physicalAttackBaseStat = config.physicalAttackBaseStat;
      specialAttackBaseStat = config.specialAttackBaseStat;
      physicalDefenceBaseStat = config.physicalDefenceBaseStat;
      specicialDefenceBaseStat = config.specicialDefenceBaseStat;
      speedBaseStat = config.speedBaseStat;
    }
  }
  void attack(Pokemon &defendingPokemon, Move &attackingMove) {
    if (attackingMove.category == status) {
    } else {
      float effectiveAttack = attackingMove.category == physical
                                  ? physicalAttack()
                                  : specialAttack();
      float effectiveDefence = attackingMove.category == physical
                                   ? defendingPokemon.physicalDefence()
                                   : defendingPokemon.specialDefence();
      float calculationStep1 = ((float)(2 * level)) / 5 + 2;
      float calculationStep2 = ((calculationStep1 * attackingMove.power *
                                 (effectiveAttack / effectiveDefence)));
      float calculationStep3 = (calculationStep2 / 50) + 2;
      // Add other factors as they come
      float randomVariance = (float)((rand() % 15) + 85) / 100;
      float calculationStep4 = calculationStep3 * randomVariance;
      defendingPokemon.HP -= calculationStep4;
    }
  }

  float calculateGenericStat(int baseStat, int individualValue = 0,
                             int effortValue = 0) {
    float step1 =
        (2 * baseStat + individualValue + (effortValue / 4.00)) * level;
    return step1 / 100.00;
  }
  float natureModifier() { return 1; }

  int maxHP() {
    return floor(calculateGenericStat(healthPointsBaseStat) + level + 10);
  }
  int physicalAttack() {
    return (calculateGenericStat(physicalAttackBaseStat) + 5) *
           natureModifier();
  }
  int physicalDefence() {
    return (calculateGenericStat(physicalDefenceBaseStat) + 5) *
           natureModifier();
  }
  int specialAttack() {
    return (calculateGenericStat(specialAttackBaseStat) + 5) * natureModifier();
  }
  int specialDefence() {
    return (calculateGenericStat(specicialDefenceBaseStat) + 5) *
           natureModifier();
  }
  int speed() {
    return (calculateGenericStat(speedBaseStat) + 5) * natureModifier();
  }

  std::string name;
  // base stats
  int healthPointsBaseStat;
  int physicalAttackBaseStat;
  int specialAttackBaseStat;
  int physicalDefenceBaseStat;
  int specicialDefenceBaseStat;
  int speedBaseStat;
  // In battle stats
  int evasion = 100;
  int accuracy = 100;
  Sprite *playerBattleSprite;
  Sprite *opposingBattleSprite;
  std::vector<Move *> availableMoves;
  // For an instance of a pokemon
  int level = 1;
  float HP = 0;
};
// Placeholders for battles
Pokemon playerCurrentPokemon("");
Pokemon opposingCurrentPokemon("");
#endif