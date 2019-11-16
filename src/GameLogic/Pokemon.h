#ifndef pokemon_h
#define pokemon_h
#include "../Config/Config.h"
#include "../Sprite.h"
#include "Pokedex.h"
#include <string>
// Keys for basic pokemon data
const std::string pokemonNameKey = "name";
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
    pokemonPlayerXKey,       pokemonPlayerYKey,       pokemonPlayerWidthKey,
    pokemonPlayerHeightKey,  pokemonOpposingXKey,     pokemonOpposingYKey,
    pokemonOpposingWidthKey, pokemonOpposingHeightKey};
struct Pokemon {
  // When created in pokedex
  Pokemon(Config config) {
    if (!config.sectionComplete(pokemonRequiredKeys)) {
      throw std::invalid_argument("Invalid pokemon configuration");
    }
    name = config[pokemonNameKey];
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
    for(std::string moveName: config.keys("availablemoves")){
      if(pokedex.availableMoves.find(moveName) != pokedex.availableMoves.end()){
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
    }
  }
  // For the config
  std::string name;
  Sprite *playerBattleSprite;
  Sprite *opposingBattleSprite;
  std::vector<Move*> availableMoves;
  // For an instance of a pokemon
  float maxHP = 0;
  float HP = 0;
};
// Placeholders for battles
Pokemon playerCurrentPokemon("");
Pokemon opposingCurrentPokemon("");
#endif