#ifndef battlebackgrounds_h
#define battlebackgrounds_h
Sprite *whiteBattleBackgroundSprite, *grassBattleBackgroundSprite,
    *waterBattleBackgroundSprite, *rockBattleBackgroundSprite,
    *pondBattleBackgroundSprite, *blueBattleBackgroundSprite,
    *yellowBattleBackgroundSprite, *purpleBattleBackgroundSprite,
    *greenBattleBackgroundSprite, *pearlBattleBackgroundSprite;
void LoadBattleBackgrounds(){
   // Row 1
  whiteBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(6, 6, 240, 112);
  grassBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(249, 6, 240, 112);
  waterBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(492, 6, 240, 112);
  // Row 2
  rockBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(6, 121, 240, 112);
  pondBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(249, 121, 240, 112);
  blueBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(492, 121, 240, 112);
  // Row 3
  yellowBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(6, 235, 240, 112);
  purpleBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(249, 235, 240, 112);
  greenBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(492, 235, 240, 112);
  // Row 4
  pearlBattleBackgroundSprite = spriteSheetStore["battlebackground"]->getPartial(6, 349, 240, 112);
}
#endif