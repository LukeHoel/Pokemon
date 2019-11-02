#ifndef pokemon_h
#define pokemon_h
#include "../Sprite.h"
#include "../Config/Config.h"
#include "Pokedex.h"
#include <string>
struct Pokemon {
  // When created in pokedex
  Pokemon(Config config){
    name = config["name"];
    Sprite* spriteSheet = spriteSheetStore[config["spritesheet"]];
    if(spriteSheet != nullptr){
      playerBattleSprite = spriteSheet->getPartial(
        std::stoi(config["playerx"]),
        std::stoi(config["playery"]),
        std::stoi(config["playerwidth"]),
        std::stoi(config["playerheight"])
      );
      opposingBattleSprite = spriteSheet->getPartial(
        std::stoi(config["opposingx"]),
        std::stoi(config["opposingy"]),
        std::stoi(config["opposingwidth"]),
        std::stoi(config["opposingheight"])
      );
    }
  }
  Pokemon(std::string name){
    // Make sure the pokemon name is valid
    if(pokedex.availablePokemon.find(name) != pokedex.availablePokemon.end()){
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