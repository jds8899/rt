#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "color.h"

class Renderer {
 public:
  Renderer(int width, int height);
  ~Renderer();
  Renderer(const Renderer& other);
  Renderer& operator=(const Renderer& other);
  void render(Color** img);
 private:
  SDL_Event event_;
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  int width_, height_;

};

#endif
