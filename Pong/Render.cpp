#include "Render.h"

Render::Render(SDL_Renderer* renderer, Ball* ball, Paddle* paddle1, Paddle* paddle2)
    : renderer(renderer), ball(ball), paddle1(paddle1), paddle2(paddle2) {
    // No-op
}

Render::~Render() {
    // Nothing to clean up.
}

void Render::draw() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_RenderClear(renderer);

    // Draw game objects
    ball->draw();
    paddle1->draw();
    paddle2->draw();

    // Update screen
    SDL_RenderPresent(renderer);
}
