#ifndef overworld_h
#define overworld_h
#include "../Sprite.h"
#include "Camera.h"
#include "OverworldEntity.h"
#include "../Battle/BattleFrontend.h"
#include "../GameLogic/Battle.h"

void drawTiles() {
  for (int i = 0; i < 50; i++) {
    for (int o = 0; o < 50; o++) {
      int xLocation = i * tileSize;
      int yLocation = o * tileSize;
      // Don't draw every tile, only needed ones
      if (camera.isObjectVisible(xLocation, yLocation, tileSize, tileSize)) {
        tiles[i][o].Draw(xLocation + camera.x, yLocation + camera.y);
      }
    }
  }
}

void movePlayer(float deltaTime) {
  if (context->GetKey(olc::Key::UP).bHeld) {
    player.y += playerSpeed * deltaTime;
    player.direction = OverworldEntity::Direction::UP;
  } else if (context->GetKey(olc::Key::DOWN).bHeld) {
    player.y -= playerSpeed * deltaTime;
    player.direction = OverworldEntity::Direction::DOWN;
  }
  if (context->GetKey(olc::Key::LEFT).bHeld) {
    player.x += playerSpeed * deltaTime;
    player.direction = OverworldEntity::Direction::LEFT;
  } else if (context->GetKey(olc::Key::RIGHT).bHeld) {
    player.x -= playerSpeed * deltaTime;
    player.direction = OverworldEntity::Direction::RIGHT;
  }
}

void drawOverworld(float deltaTime) {
  context->SetPixelMode(olc::Pixel::NORMAL);
  drawTiles();
  context->SetPixelMode(olc::Pixel::MASK);
  testAnimation.Draw(10, 10, deltaTime);
  player.Draw();
  movePlayer(deltaTime);
  if (context->GetKey(olc::Key::ENTER).bPressed) {
    opposingTrainer = Trainer(Config("config/trainers/blue.config"));
    currentBattle = new Battle(&playerTrainer, &opposingTrainer);
    StartBattle();
  }
  // Camera follow
  camera.x = player.x;
  camera.y = player.y;
}
#endif