#ifndef battlebackgrounds_h
#define battlebackgrounds_h
Sprite *whiteBattleBackgroundSprite, *grassBattleBackgroundSprite,
    *waterBattleBackgroundSprite, *rockBattleBackgroundSprite,
    *pondBattleBackgroundSprite, *blueBattleBackgroundSprite,
    *yellowBattleBackgroundSprite, *purpleBattleBackgroundSprite,
    *greenBattleBackgroundSprite, *pearlBattleBackgroundSprite;
void LoadBattleBackgrounds(){
  // Battle backgrounds
  olc::Sprite *fireRedBattleBackgroundsSpriteSheet = new olc::Sprite(spriteSheets+"fireRedBattleBackgrounds.png");
  // Row 1
  whiteBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 6, 6, 240, 112);
  grassBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 249, 6, 240, 112);
  waterBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 492, 6, 240, 112);
  // Row 2
  rockBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  6, 121, 240, 112);
  pondBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  249, 121, 240, 112);
  blueBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  492, 121, 240, 112);
  // Row 3
  yellowBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet, 6, 235, 240, 112);
  purpleBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  249, 235, 240, 112);
  greenBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  492, 235, 240, 112);
  // Row 4
  pearlBattleBackgroundSprite = new Sprite(fireRedBattleBackgroundsSpriteSheet,  6, 349, 240, 112);
}
#endif