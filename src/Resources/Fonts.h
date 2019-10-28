#ifndef fonts_h
#define fonts_h
#include "../Sprite.h"
#include <string>
#include <unordered_map>
typedef std::unordered_map<char, Sprite *> SpriteFont;
SpriteFont fireRedBattleEffectFont;
void LoadFonts() {
  Sprite *fireRedBattleEffectFontSpriteSheet =
      new Sprite(images + "fireRedBattleEffects.png");
  int firstLine = 124;
  int fontWidth = 5;
  int fontHeight = 8;
  // First Line
  fireRedBattleEffectFont[' '] = fireRedBattleEffectFontSpriteSheet->getPartial(166,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['A'] = fireRedBattleEffectFontSpriteSheet->getPartial(171,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['B'] = fireRedBattleEffectFontSpriteSheet->getPartial(178,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['C'] = fireRedBattleEffectFontSpriteSheet->getPartial(185,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['D'] = fireRedBattleEffectFontSpriteSheet->getPartial(192,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['E'] = fireRedBattleEffectFontSpriteSheet->getPartial(199,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['F'] = fireRedBattleEffectFontSpriteSheet->getPartial(206,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['G'] = fireRedBattleEffectFontSpriteSheet->getPartial(213,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['H'] = fireRedBattleEffectFontSpriteSheet->getPartial(220,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['I'] = fireRedBattleEffectFontSpriteSheet->getPartial(227,firstLine,fontWidth-1,fontHeight);
  fireRedBattleEffectFont['J'] = fireRedBattleEffectFontSpriteSheet->getPartial(233,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['K'] = fireRedBattleEffectFontSpriteSheet->getPartial(240,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['L'] = fireRedBattleEffectFontSpriteSheet->getPartial(247,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['M'] = fireRedBattleEffectFontSpriteSheet->getPartial(254,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['N'] = fireRedBattleEffectFontSpriteSheet->getPartial(261,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['O'] = fireRedBattleEffectFontSpriteSheet->getPartial(268,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['P'] = fireRedBattleEffectFontSpriteSheet->getPartial(275,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['Q'] = fireRedBattleEffectFontSpriteSheet->getPartial(282,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['R'] = fireRedBattleEffectFontSpriteSheet->getPartial(289,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['S'] = fireRedBattleEffectFontSpriteSheet->getPartial(296,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['T'] = fireRedBattleEffectFontSpriteSheet->getPartial(303,firstLine,fontWidth-1,fontHeight);
  fireRedBattleEffectFont['U'] = fireRedBattleEffectFontSpriteSheet->getPartial(309,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['V'] = fireRedBattleEffectFontSpriteSheet->getPartial(316,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['W'] = fireRedBattleEffectFontSpriteSheet->getPartial(323,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['X'] = fireRedBattleEffectFontSpriteSheet->getPartial(330,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['Y'] = fireRedBattleEffectFontSpriteSheet->getPartial(337,firstLine,fontWidth-1,fontHeight);
  fireRedBattleEffectFont['Z'] = fireRedBattleEffectFontSpriteSheet->getPartial(343,firstLine,fontWidth,fontHeight);
  fireRedBattleEffectFont['.'] = fireRedBattleEffectFontSpriteSheet->getPartial(351,firstLine,fontWidth-2,fontHeight);
  fireRedBattleEffectFont[','] = fireRedBattleEffectFontSpriteSheet->getPartial(358,firstLine,fontWidth-2,fontHeight+1);
}
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