#ifndef resources_h
#define resources_h
#include <string>
std::string images("resources/images/");
Sprite *placeholder;
void InitializeResources() {
  placeholder = new Sprite(images + "placeholder.png");
}
#endif