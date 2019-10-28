#ifndef sprite_h
#define sprite_h
#include <string>
class Sprite {
  bool usePartial = false;
  int partialX;
  int partialY;
  int partialWidth;
  int partialHeight;
  olc::Sprite *innerSprite = nullptr;

public:
  Sprite() {}
  Sprite(std::string fileName) : innerSprite(new olc::Sprite(fileName)) {}
  Sprite(olc::Sprite *sprite) : innerSprite(sprite) {}
  Sprite(olc::Sprite *sprite, int partialX, int partialY, int partialWidth,
         int partialHeight)
      : innerSprite(sprite), usePartial(true), partialX(partialX),
        partialY(partialY), partialWidth(partialWidth),
        partialHeight(partialHeight) {}
  // Take the other sprite and copy the references, possibly changing the partial values
  Sprite(Sprite *other, int partialX, int partialY, int partialWidth,
         int partialHeight)
      : innerSprite(other->innerSprite), partialX(partialX), partialY(partialY),
        partialWidth(partialWidth), partialHeight(partialHeight) {}

  ~Sprite() { delete innerSprite; }
  void Draw(int x, int y, int scale = 1) {
    if (innerSprite != nullptr) {
      // Draw select part of the sprite, possibly a sprite sheet
      if (usePartial) {
        context->DrawPartialSprite(x, y, innerSprite, partialX, partialY,
                                   partialWidth, partialHeight, scale);
      } else {
        context->DrawSprite(x, y, innerSprite, scale);
      }
    }
  }
  int width() { return partialWidth; }
  int height() { return partialHeight; }
  // Copies the data over, flipping along the Y axis
  // If the current object was a part of a spritesheet, that connection is lost
  // as part of this action
  Sprite *flipAlongYAxis() {
    Sprite *ret = new Sprite();
    ret->innerSprite = new olc::Sprite(partialWidth, partialHeight);
    for (int i = 0; i < partialWidth; i++) {
      for (int o = 0; o < partialHeight; o++) {
        ret->innerSprite->SetPixel(
            partialWidth - 1 - i, o,
            innerSprite->GetPixel(partialX + i, partialY + o));
      }
    }
    return ret;
  }
  // Copies the data over, flipping along the X axis
  // If the current object was a part of a spritesheet, that connection is lost
  // as part of this action
  Sprite *flipAlongXAxis() {
    Sprite *ret = new Sprite();
    ret->innerSprite = new olc::Sprite(partialWidth, partialHeight);
    for (int i = 0; i < partialWidth; i++) {
      for (int o = 0; o < partialHeight; o++) {
        ret->innerSprite->SetPixel(
            i, partialHeight - 1 - o,
            innerSprite->GetPixel(partialX + i, partialY + o));
      }
    }
    return ret;
  }
  // Return this same sprite, only with different points shown
  Sprite *getPartial(int partialX, int partialY, int partialWidth,
                     int partialHeight) {
    Sprite *ret = new Sprite();
    ret->innerSprite = this->innerSprite;
    ret->usePartial = true;
    ret->partialX = partialX;
    ret->partialY = partialY;
    ret->partialWidth = partialWidth;
    ret->partialHeight = partialHeight;
    return ret;
  }
};
#endif