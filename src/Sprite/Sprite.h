#ifndef sprite_h
#define sprite_h
#include <string>
class Sprite {

public:
  olc::Sprite *innerSprite = nullptr;

  Sprite() {}
  Sprite(std::string fileName) { innerSprite = new olc::Sprite(fileName); }
  ~Sprite() { delete innerSprite; }
  void Draw(int x, int y, int scale = 1) {
    if (innerSprite != nullptr) {
      context->DrawSprite(x, y, innerSprite);
    }
  }
};
#endif