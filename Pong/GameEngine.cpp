#include "GameEngine.h"
#include <cstdlib>
#include<iostream>
GameEngine::GameEngine(SDL_Renderer* renderer)
    : renderer(renderer), running(true) {
    ball = new Ball(renderer, 400, 300, 15, 15);
    paddle1 = new Paddle(renderer, 50, 300, 10, 80, { 0, 255, 0, 255 }); // Green paddle
    paddle2 = new Paddle(renderer, 740, 300, 10, 80, { 128, 0, 128, 255 }); // Purple paddle
}

GameEngine::~GameEngine() {
    delete ball;
    delete paddle1;
    delete paddle2;
}

void GameEngine::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                paddle2->moveUp();
                break;
            case SDLK_DOWN:
                paddle2->moveDown();
                break;
            case SDLK_w:
                paddle1->moveUp();
                break;
            case SDLK_s:
                paddle1->moveDown();
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_DOWN:
                paddle2->stop();
                break;
            case SDLK_w:
            case SDLK_s:
                paddle1->stop();
                break;
            }
            break;
        }
    }
}

void GameEngine::update() {
    ball->update();
    paddle1->update();
    paddle2->update();
}

void GameEngine::draw() {
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

bool GameEngine::isRunning() {
    return running;
}
void GameEngine::detectCollisions() {
    SDL_Rect ballRect = ball->getRect();
    SDL_Rect paddle1Rect = paddle1->getRect();
    SDL_Rect paddle2Rect = paddle2->getRect();

    // Check for collision with paddle1
    if (SDL_HasIntersection(&ballRect, &paddle1Rect)) {
        ball->bounceHorizontal();
        ball->bounceVertical();
    }
    // Check for collision with paddle2
    if (SDL_HasIntersection(&ballRect, &paddle2Rect)) {
        ball->bounceHorizontal();
        ball->bounceVertical();
    }
    // Check for scoring
    if (ballRect.x <= 0) {
        std::cout << "Player 2 Scores: " << std::endl;
        // Here you could update the score and then respawn the ball
        ball->respawn(400, 300);
    }
    if (ballRect.x + ballRect.w >= 800) {
        std::cout << "Player 1 Scores: " << std::endl;
        // Here you could update the score and then respawn the ball
        ball->respawn(400, 300);
    }
}
