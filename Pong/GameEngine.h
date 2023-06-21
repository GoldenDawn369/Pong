#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL.h>
#include "Ball.h"
#include "Paddle.h"
#include "Menu.h"

class GameEngine {
public:
    GameEngine(SDL_Renderer* renderer);
    ~GameEngine();

    void handleInput();
    void update();
    void draw();
    void detectCollisions();
    bool isRunning();
    void detectPowerUp();
    int getPlayer1Score() const;
    int getPlayer2Score() const;

private:
    SDL_Renderer* renderer;
    Ball* ball;
    Paddle* paddle1;
    Paddle* paddle2;
    bool running;
    Menu* menu;
    int player1Score;
    int player2Score;
};

#endif // GAMEENGINE_H
