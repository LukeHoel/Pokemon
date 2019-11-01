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
  for(std::string spriteKeyName: spriteSheetConfig.keys){ spriteSheetStore[spriteKeyName] = new Sprite(spriteSheetConfig.map[spriteKeyName]); }
  // Get the pokemon configs
  for(std::string pokemonKeyName: pokedexConfig.keys) { 
    pokedex.availablePokemon[pokemonKeyName] = new Pokemon(Config(pokedexConfig.map[pokemonKeyName]));
  }
  // Main tileset spritesheets
  olc::Sprite *fireRedTileset1SpriteSheet = new olc::Sprite(spriteSheets + "fireRedTileset1.png");
  olc::Sprite *fireRedTileset2SpriteSheetSpriteSheet = new olc::Sprite(spriteSheets + "fireRedTileset2.png");
  olc::Sprite *fireRedTileset2 = new olc::Sprite(spriteSheets + "fireRedTileset3.png");
  grassSprite = new Sprite(fireRedTileset1SpriteSheet, 6, 64, tileSize, tileSize);
  // Player spritesheet
  olc::Sprite *fireRedPlayerSpriteSheet = new olc::Sprite(spriteSheets + "fireRedPlayer.png");
  playerUpSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 68, tileSize, 20);
  playerDownSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 36, tileSize, 20);
  playerLeftSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 100, tileSize, 20);
  playerRightSprite = playerLeftSprite->flipAlongYAxis();
  testAnimation = Animation(5, {playerUpSprite, playerRightSprite, playerDownSprite, playerLeftSprite});
  LoadBattleBackgrounds();
  LoadFireRedBattleEffectFont();
}
#endif
// clang-format on