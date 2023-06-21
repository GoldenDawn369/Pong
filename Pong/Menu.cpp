#include "Menu.h"

Menu::Menu(SDL_Renderer* renderer)
    : renderer(renderer), readyToStart(false) {}

Menu::~Menu() {}

void Menu::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
            readyToStart = true;
        }
    }
}

void Menu::update() {}

void Menu::draw() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_RenderClear(renderer);

    // Draw menu text or graphics
    // ...

    // Update screen
    SDL_RenderPresent(renderer);
}

bool Menu::isReadyToStart() {
    return readyToStart;
}
