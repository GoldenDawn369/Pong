#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>

class Paddle {
public:
    Paddle(SDL_Renderer* renderer, int startX, int startY, int paddleWidth, int paddleHeight, SDL_Color color);
    ~Paddle();

    void draw();
    void update();
    void moveUp();
    void moveDown();
    void stop();

    SDL_Rect getRect();

private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Color color;
    float yPosition; // This will store the exact position of the paddle
    float dy; // This will store the vertical velocity of the paddle
};

#endif // PADDLE_H
