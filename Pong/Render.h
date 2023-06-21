#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>
#include "Ball.h"
#include "Paddle.h"

class Render {
public:
    Render(SDL_Renderer* renderer, Ball* ball, Paddle* paddle1, Paddle* paddle2);
    ~Render();

    void draw();

private:
    SDL_Renderer* renderer;
    Ball* ball;
    Paddle* paddle1;
    Paddle* paddle2;
};

#endif // RENDER_H
