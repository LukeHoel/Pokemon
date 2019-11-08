#ifndef menu_h
#define menu_h
#include "Resources/Font.h"
#include <string>
#include <vector>
#include <initializer_list>
struct Menu {
  SpriteFont *spriteFont;
  std::vector<std::string> menuItems;
  Menu(SpriteFont *spriteFont, std::initializer_list<std::string> menuItems):
    spriteFont(spriteFont), menuItems(menuItems){}
  void Draw(int x, int y, int itemYSpacing = 10) {
    int yOffset = 0;
    for (std::string menuItem : menuItems) {
      DrawSpriteString(menuItem, x, y + yOffset, *spriteFont);
      yOffset += itemYSpacing;
    }
  }
};
#endif