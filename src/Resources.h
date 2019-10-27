// clang-format off
#ifndef resources_h
#define resources_h
#include <string>
std::string images("resources/images/");
Sprite *grassSprite, *playerUpSprite, *playerDownSprite, *playerLeftSprite,
    *playerRightSprite;
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
}
#endif
// clang-format on