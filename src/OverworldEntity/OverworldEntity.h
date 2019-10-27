#ifndef overworld_entity_h
#define overworld_entity_h
struct OverworldEntity {
  enum Direction { UP, DOWN, LEFT, RIGHT };
  float x = 0;
  float y = 0;
  bool drawCentered;
  Direction direction;
  Sprite *upSprite, *downSprite, *leftSprite, *rightSprite;
  OverworldEntity(){};
  OverworldEntity(Sprite *upSprite, Sprite *downSprite, Sprite *leftSprite,
                  Sprite *rightSprite, float x = 0, float y = 0)
      : upSprite(upSprite), downSprite(downSprite), leftSprite(leftSprite),
        rightSprite(rightSprite), x(x), y(y) {}
  void Draw() {
    Sprite *drawnSprite;
    switch (direction) {
    case (UP):
      drawnSprite = upSprite;
      break;
    case (DOWN):
      drawnSprite = downSprite;
      break;
    case (LEFT):
      drawnSprite = leftSprite;
      break;
    case (RIGHT):
      drawnSprite = rightSprite;
      break;
    }
    if (drawCentered) {
      DrawCentered(drawnSprite);
    } else {
      DrawRegular(drawnSprite);
    }
  }
  void DrawRegular(Sprite *sprite) { sprite->Draw(x, y); }
  // Same as DrawRegular, but corrects for camera
  void DrawCentered(Sprite *sprite) {
    sprite->Draw(x - camera.x + amountPixelsX / 2,
                 y - camera.y + amountPixelsY / 2);
  }
};
#endif