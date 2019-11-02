// clang-format off
#ifndef resources_h
#define resources_h
#include <string>
#include <unordered_map>
std::string spriteSheets("resources/spriteSheets/");
#include "BattleBackgrounds.h"
#include "Fonts/fireRedBattleEffectFont.h"
#include "../GameLogic/Pokedex.h"
#include "../GameLogic/Pokemon.h"
// Tiles
Sprite *grassSprite;
// Player
Sprite  *playerUpSprite,
        *playerDownSprite,
        *playerLeftSprite,
        *playerRightSprite;
// Battle backgrounds
Animation testAnimation;

// Set up sprite sheet store (using sprite sheet store)
Config spriteSheetConfig("config/spriteSheets.config");
// Set up pokemon store (using the pokedex)
Config pokedexConfig("config/pokedex.config");
// Pokemon sprites
Sprite* fireRedPokemonSpriteSheet; 
void LoadResources() {
  // Get the sprite sheet config and put it into the mapping
  for(std::string spriteKeyName: spriteSheetConfig.keys){ spriteSheetStore[spriteKeyName] = new Sprite(spriteSheetConfig[spriteKeyName]); }
  // Get the pokemon configs
  for(std::string pokemonKeyName: pokedexConfig.keys) { pokedex.availablePokemon[pokemonKeyName] = new Pokemon(Config(pokedexConfig[pokemonKeyName])); }
  LoadBattleBackgrounds();
  LoadFireRedBattleEffectFont();
  grassSprite = spriteSheetStore["tileset1"]->getPartial(6, 64, tileSize, tileSize);
  // Player spritesheet
  playerUpSprite = spriteSheetStore["player"]->getPartial(24, 68, tileSize, 20);
  playerDownSprite = spriteSheetStore["player"]->getPartial(24, 36, tileSize, 20);
  playerLeftSprite = spriteSheetStore["player"]->getPartial(24, 100, tileSize, 20);
  playerRightSprite = playerLeftSprite->flipAlongYAxis();
  testAnimation = Animation(5, {playerUpSprite, playerRightSprite, playerDownSprite, playerLeftSprite});
}
#endif
// clang-format on