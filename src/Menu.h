#ifndef menu_h
#define menu_h
#include "Resources/Font.h"
#include <initializer_list>
#include <string>
#include <vector>
void noop(){}
struct MenuItem{
  std::string displayName;
  void (*onSelect)() = &noop;
};
class Menu {
  int selectedIndex = 0;

public:
  SpriteFont *spriteFont;
  std::vector<MenuItem> menuItems;
  Menu(){}
  Menu(SpriteFont *spriteFont, std::initializer_list<MenuItem> menuItems)
      : spriteFont(spriteFont), menuItems(menuItems) {}
  bool active = false;
  void Reset(){
    active = false;
    selectedIndex = 0;
  }
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
      DrawSpriteString(menuItems[i].displayName, x, y + yOffset, *spriteFont);
      yOffset += itemYSpacing;
      if (active && i == selectedIndex) {
        int circleRadius = 2;
        int circleX = x - 5;
        int circleY = y + yOffset - circleRadius - itemYSpacing / 2;
        context->FillCircle(circleX, circleY, circleRadius, olc::WHITE);
        context->DrawCircle(circleX, circleY, circleRadius, olc::DARK_GREY);
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
      if(context->GetKey(olc::ENTER).bPressed){
        menuItems[selectedIndex].onSelect();
      }
    }
  }
};
#endif