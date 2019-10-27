#ifndef resources_h
#define resources_h
#include <string>
std::string images("resources/images/");
Sprite *placeholderSprite, *playerUpSprite, *playerDownSprite,
    *playerLeftSprite, *playerRightSprite;
void InitializeResources() {
  placeholderSprite = new Sprite(images + "placeholder.png");
  // Use sprite sheet to get partials off of
  olc::Sprite *fireredplayerSprite =
      new olc::Sprite(images + "fireredplayer.png");
  playerUpSprite = new Sprite(fireredplayerSprite, 24, 68, 16, 20);
  playerDownSprite = new Sprite(fireredplayerSprite, 24, 36, 16, 20);
  playerLeftSprite = new Sprite(fireredplayerSprite, 24, 100, 16, 20);
  playerRightSprite = playerLeftSprite->flipAlongYAxis();
}
#endif