#ifndef pokemon_h
#define pokemon_h
#include "../Sprite.h"
struct Pokemon {
  float maxHP = 0;
  float HP = 0;
  Sprite *battleSprite;
};
// Placeholders for battles
Pokemon playerCurrentPokemon;
Pokemon opposingCurrentPokemon;
#endif