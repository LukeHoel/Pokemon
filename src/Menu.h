#ifndef menu_h
#define menu_h
#include "Resources/Font.h"
#include <initializer_list>
#include <string>
#include <vector>
class Menu {
  int selectedIndex = 0;

public:
  SpriteFont *spriteFont;
  std::vector<std::string> menuItems;
  Menu(SpriteFont *spriteFont, std::initializer_list<std::string> menuItems)
      : spriteFont(spriteFont), menuItems(menuItems) {}
  bool active = false;
  void Previous() {
    selectedIndex--;
    if (selectedIndex < 0) {
      selectedIndex = menuItems.size() - 1;
    }
  }
  void Next() {
    selectedIndex++;
    if (selectedIndex > menuItems.size() - 1) {
      selectedIndex = 0;
    }
  }
  void Draw(int x, int y, int itemYSpacing = 10) {

    int yOffset = 0;
    for (size_t i = 0; i < menuItems.size(); i++) {
      DrawSpriteString(menuItems[i], x, y + yOffset, *spriteFont);
      yOffset += itemYSpacing;
      if (active && i == selectedIndex) {
        context->DrawCircle(x - 5, y + yOffset - 2 - itemYSpacing / 2, 2,
                            olc::DARK_GREY);
      }
    }
    if (active) {
      // Change menu selection
      if (context->GetKey(olc::UP).bPressed) {
        Previous();
      }
      if (context->GetKey(olc::DOWN).bPressed) {
        Next();
      }
    }
  }
};
#endif