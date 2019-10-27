// clang-format off
#ifndef resources_h
#define resources_h
#include <string>
std::string images("resources/images/");
// Tiles
Sprite *grassSprite;
// Player
Sprite  *playerUpSprite,
        *playerDownSprite,
        *playerLeftSprite,
        *playerRightSprite;
// Battle backgrounds
Sprite  *whiteBattleBackgroundSprite,
        *grassBattleBackgroundSprite,
        *waterBattleBackgroundSprite,
        *rockBattleBackgroundSprite,
        *pondBattleBackgroundSprite,
        *blueBattleBackgroundSprite,
        *yellowBattleBackgroundSprite,
        *purpleBattleBackgroundSprite,
        *greenBattleBackgroundSprite,
        *pearlBattleBackgroundSprite;
Animation testAnimation;
void InitializeResources() {
  // Main tileset spritesheets
  olc::Sprite *fireRedTileset1SpriteSheet = new olc::Sprite(images + "fireRedTileset1.png");
  olc::Sprite *fireRedTileset2SpriteSheetSpriteSheet = new olc::Sprite(images + "fireRedTileset2.png");
  olc::Sprite *fireRedTileset2 = new olc::Sprite(images + "fireRedTileset3.png");
  grassSprite = new Sprite(fireRedTileset1SpriteSheet, 6, 64, tileSize, tileSize);
  // Player spritesheet
  olc::Sprite *fireRedPlayerSpriteSheet = new olc::Sprite(images + "fireRedPlayer.png");
  playerUpSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 68, tileSize, 20);
  playerDownSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 36, tileSize, 20);
  playerLeftSprite = new Sprite(fireRedPlayerSpriteSheet, 24, 100, tileSize, 20);
  playerRightSprite = playerLeftSprite->flipAlongYAxis();
  testAnimation = Animation(5, {playerUpSprite, playerRightSprite, playerDownSprite, playerLeftSprite});
  // Battle backgrounds
  olc::Sprite *fireRedBattleBackgroundsSpriteSheet = new olc::Sprite(images+"fireRedBattleBackgrounds.png");
  // Row 1
  whiteBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 6, 6, 240, 112);
  grassBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 249, 6, 240, 112);
  waterBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 492, 6, 240, 112);
  // Row 2
  rockBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  6, 121, 240, 112);
  pondBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  249, 121, 240, 112);
  blueBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  492, 121, 240, 112);
  // Row 3
  yellowBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 6, 235, 240, 112);
  purpleBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  249, 235, 240, 112);
  greenBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  492, 235, 240, 112);
  // Row 4
  pearlBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  6, 349, 240, 112);
}
#endif
// clang-format on