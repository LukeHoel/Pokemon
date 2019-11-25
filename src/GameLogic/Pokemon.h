#ifndef pokemon_h
#define pokemon_h
#include "../Config/Config.h"
#include "../Sprite.h"
#include "Pokedex.h"
#include "PokemonSpecies.h"

#include <string>
std::string pokemonSpeciesKey = "species";
std::string pokemonLevelKey = "level";
std::string pokemonHPKey = "hp";
// HP isn't required, set to full by default
std::initializer_list<std::string> pokemonRequiredKeys = {pokemonSpeciesKey,
                                                          pokemonLevelKey};
struct Pokemon {
  PokemonSpecies &species;
  // In battle stats
  int evasion = 100;
  int accuracy = 100;

  // For an instance of a pokemon
  int level = 1;
  float HP = 0;
  Pokemon(Config config)
      : species(*pokedex.availablePokemon[config[pokemonSpeciesKey]]),
        level(std::stoi(config[pokemonLevelKey])) {
    // Assume full by default
    if (config[pokemonHPKey].empty()) {
      HP = maxHP();
    } else {
      HP = std::stoi(config[pokemonHPKey]);
    }
  }
  Pokemon(const Pokemon &other)
      : species(other.species), level(other.level), HP(other.HP) {}
  Pokemon &operator=(const Pokemon &other) {
    species = other.species;
    level = other.level;
    HP = other.HP;
    return *this;
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
    return floor(calculateGenericStat(species.healthPointsBaseStat) + level +
                 10);
  }
  int physicalAttack() {
    return (calculateGenericStat(species.physicalAttackBaseStat) + 5) *
           natureModifier();
  }
  int physicalDefence() {
    return (calculateGenericStat(species.physicalDefenceBaseStat) + 5) *
           natureModifier();
  }
  int specialAttack() {
    return (calculateGenericStat(species.specialAttackBaseStat) + 5) *
           natureModifier();
  }
  int specialDefence() {
    return (calculateGenericStat(species.specicialDefenceBaseStat) + 5) *
           natureModifier();
  }
  int speed() {
    return (calculateGenericStat(species.speedBaseStat) + 5) * natureModifier();
  }
};
#endif