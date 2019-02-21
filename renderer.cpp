#include "renderer.h"

Renderer::Renderer(int width, int height) :
  event_{},
  window_{NULL},
  renderer_{NULL},
  width_{width},
  height_{height} {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &window_, &renderer_);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

Renderer::Renderer(const Renderer& other) :
  event_{other.event_},
  window_{other.window_},
  renderer_{other.renderer_},
  width_{other.width_},
  height_{other.height_} {}

Renderer& Renderer::operator=(const Renderer& other) {
  return *this;;
}

void Renderer::render(Color** img) {
  for(int i = 0; i < height_; ++i) {
    for(int j = 0; j < width_; ++j) {
      Color curr = img[i][j];
      SDL_SetRenderDrawColor(renderer_,
                             (unsigned)(curr.r() * 255),
                             (unsigned)(curr.g() * 255),
                             (unsigned)(curr.b() * 255), 0);
      SDL_RenderDrawPoint(renderer_, j, height_ - i);
    }
  }
  SDL_RenderPresent(renderer_);

  for(;;) {
    if (SDL_PollEvent(&event_) && event_.type == SDL_QUIT)
      break;
  }
}
