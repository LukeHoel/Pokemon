// clang-format off
#ifndef resources_h
#define resources_h
#include <string>
std::string spriteSheets("resources/spriteSheets/");
#include "BattleBackgrounds.h"
#include "Fonts/fireRedBattleEffectFont.h"
// Tiles
Sprite *grassSprite;
// Player
Sprite  *playerUpSprite,
        *playerDownSprite,
        *playerLeftSprite,
        *playerRightSprite;
// Battle backgrounds
Animation testAnimation;
// Pokemon sprites
Sprite* fireRedPokemonSpriteSheet; 
void LoadResources() {
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
  // Pokemon spritesheet
  fireRedPokemonSpriteSheet = new Sprite(spriteSheets+"fireRedBattleSpritesGen1.png");
  LoadBattleBackgrounds();
  LoadFireRedBattleEffectFont();
}
#endif
// clang-format on