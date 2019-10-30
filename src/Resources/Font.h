#ifndef fonts_h
#define fonts_h
#include "../Sprite.h"
#include <string>
#include <unordered_map>
// A font is just a mapping of a character to a sprite
typedef std::unordered_map<char, Sprite *> SpriteFont;
// Draw a string according to the mapping
void DrawSpriteString(std::string str, int x, int y, SpriteFont &font) {
  int xOffset = 0;
  for (char &ch : str) {
    Sprite *sprite = font[ch];
    if (sprite != nullptr) {
      sprite->Draw(x + xOffset, y);
      xOffset += sprite->width();
    }
  }
}
#endif