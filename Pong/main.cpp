#include <SDL.h>
#include "Window.h"
#include "GameEngine.h"

int SDL_main(int argc, char* argv[]) {
    Window window("Pong Game", 800, 600);
    SDL_Renderer* renderer = window.getRenderer();

    GameEngine gameEngine(renderer);

    while (gameEngine.isRunning()) {
        gameEngine.handleInput();
        gameEngine.update();
        gameEngine.draw();
        gameEngine.detectCollisions();
    }

    return 0;
}
