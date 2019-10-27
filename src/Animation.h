#ifndef animation_h
#define animation_h
#include <vector>
class Animation {
  float timer = 0;

public:
  std::vector<Sprite *> frames;
  float speed = 0;
  int currentFrameIndex = 0;
  Animation() {}
  Animation(float speed, std::vector<Sprite *> frames = std::vector<Sprite *>())
      : speed(speed), frames(frames) {}
  void Draw(int x, int y, float deltaTime, int scale = 1) {
    timer += speed * deltaTime;
    if (timer > 1) {
      timer = 0;
      currentFrameIndex++;
      if (currentFrameIndex > frames.size() - 1) {
        currentFrameIndex = 0;
      }
    }
    frames[currentFrameIndex]->Draw(x, y, scale);
  }
};
#endif