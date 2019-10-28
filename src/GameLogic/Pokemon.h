#ifndef pokemon_h
#define pokemon_h
#include "../Sprite.h"
#include <string>
struct Pokemon {
  std::string name;
  float maxHP = 0;
  float HP = 0;
  Sprite *battleSprite;
};
// Placeholders for battles
Pokemon playerCurrentPokemon;
Pokemon opposingCurrentPokemon;
#endif