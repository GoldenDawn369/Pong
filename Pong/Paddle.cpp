#include "Paddle.h"

Paddle::Paddle(SDL_Renderer* renderer, int startX, int startY, int paddleWidth, int paddleHeight, SDL_Color color)
    : renderer(renderer), yPosition(startY), dy(0.0f), color(color) {
    rect.x = startX;
    rect.y = startY;
    rect.w = paddleWidth;
    rect.h = paddleHeight;
}
Paddle::~Paddle() {
    // Nothing to clean up.
}

void Paddle::draw() {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Color set in constructor
    SDL_RenderFillRect(renderer, &rect);
}

void Paddle::update() {
    // Move the paddle
    yPosition += dy;

    // If the paddle goes off the top of the screen, make it reappear at the bottom
    if (yPosition < -rect.h) {
        yPosition = 600;  // 600 is the height of the screen
    }
    // If the paddle goes off the bottom of the screen, make it reappear at the top
    if (yPosition > 600) { // 600 is the height of the screen
        yPosition = -rect.h;
    }

    rect.y = static_cast<int>(yPosition); // convert the position to an int when rendering
}

void Paddle::moveUp() {
    dy = -0.3;
}

void Paddle::moveDown() {
    dy = 0.3;
}

void Paddle::stop() {
    dy = 0;
}
SDL_Rect Paddle::getRect() {
    return rect;
}
