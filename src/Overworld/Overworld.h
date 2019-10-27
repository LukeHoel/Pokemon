#ifndef overworld_h
#define overworld_h
#include "../Sprite.h"
#include "Camera.h"
#include "OverworldEntity.h"

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
  drawTiles();
  testAnimation.Draw(10, 10, deltaTime);
  context->SetPixelMode(olc::Pixel::MASK);
  player.Draw();
  movePlayer(deltaTime);
  if (context->GetKey(olc::Key::ENTER).bPressed) {
    mode = Mode::BATTLE;
  }
  // Camera follow
  camera.x = player.x;
  camera.y = player.y;
}
#endif