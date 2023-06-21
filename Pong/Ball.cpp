#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer, int startX, int startY, int ballWidth, int ballHeight)
    : renderer(renderer), xPosition(startX), yPosition(startY), dx(10.0f), dy(10.0f) {
    rect.x = startX;
    rect.y = startY;
    rect.w = ballWidth;
    rect.h = ballHeight;
}
Ball::~Ball() {
    // Nothing to clean up.
}
void Ball::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::update() {
    // Move the ball
    xPosition += dx;
    yPosition += dy;
    rect.x = static_cast<int>(xPosition); // convert the position to an int when rendering
    rect.y = static_cast<int>(yPosition); // convert the position to an int when rendering

    // If the ball hits the top or the bottom of the screen, reverse the y direction
    if (rect.y <= 0 || rect.y + rect.h >= 600) { // 600 is the height of the screen
        dy = -dy;
    }

    // If the ball hits the left or the right of the screen, reverse the x direction
    if (rect.x <= 0 || rect.x + rect.w >= 800) { // 800 is the width of the screen
        dx = -dx;
    }
}

SDL_Rect Ball::getRect() {
    return rect;
}
void Ball::respawn(int startX, int startY) {
    xPosition = startX;
    yPosition = startY;
    dx = 0.15f;
    dy = 0.15f;
}
void Ball::bounceHorizontal() {
    dx = -dx;
}

void Ball::bounceVertical() {
    dy = -dy;
}
void Ball::doubleSpeed() {
    dx *= 2;
    dy *= 2;
}