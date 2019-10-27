#ifndef camera_h
#define camera_h
struct Camera {
  float x = 0;
  float y = 0;
  bool isObjectVisible(float x, float y, int width, int height) {
    // Don't draw every tile, only needed ones
    bool insideLeftBound = x + width + this->x > 0;
    bool insideRightBound = x + this->x < amountPixelsX;
    bool insideTopBound = y + height + this->y > 0;
    bool insideBottomBound = y + this->y < amountPixelsY;
    return insideLeftBound && insideRightBound && insideTopBound &&
           insideBottomBound;
  }
};
// Make an instance of the camera for use in the overworld
Camera camera;
#endif