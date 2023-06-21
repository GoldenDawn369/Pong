#include "Window.h"
#include <iostream>
Window::Window(const char* title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO); //Initialize SDL2
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == nullptr || renderer == nullptr) {
        // In the case that the window could not be made...
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        closed = true;
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear() const {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
}

void Window::update() const {
    SDL_RenderPresent(renderer);
}

bool Window::isClosed() const {
    return closed;
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}
