bool isInsideCamera(float x, float y, int width, int height) {
  // Don't draw every tile, only needed ones
  bool insideLeftBound = x + width + camera.x > 0;
  bool insideRightBound = x + camera.x < amountPixelsX;
  bool insideTopBound = y + height + camera.y > 0;
  bool insideBottomBound = y + camera.y < amountPixelsY;
  if (insideLeftBound && insideRightBound && insideTopBound &&
      insideBottomBound) {
  }
}