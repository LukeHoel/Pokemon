#ifndef tile_h
#define tile_h
struct Tile {
  Sprite *sprite;
  Tile(Sprite *sprite = nullptr) : sprite(sprite) {}
  void Draw(int x, int y) { sprite->Draw(x, y); }
};
#endif