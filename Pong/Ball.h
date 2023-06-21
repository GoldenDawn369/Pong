#ifndef BALL_H
#define BALL_H

#include <SDL.h>

class Ball {
public:
    Ball(SDL_Renderer* renderer, int startX, int startY, int ballWidth, int ballHeight);
    ~Ball();

    void draw();
    void update();
    void respawn(int startX, int startY);
    void bounceHorizontal();
    void bounceVertical();
    SDL_Rect getRect();
    void doubleSpeed();

private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    float xPosition; // This will store the exact position of the ball in the x direction
    float yPosition; // This will store the exact position of the ball in the y direction
    float dx; // This will store the horizontal velocity of the ball
    float dy; // This will store the vertical velocity of the ball
};

#endif // BALL_H
