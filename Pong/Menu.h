#ifndef MENU_H
#define MENU_H

#include <SDL.h>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    ~Menu();

    void handleInput();
    void update();
    void draw();
    bool isReadyToStart();

private:
    SDL_Renderer* renderer;
    bool readyToStart;
};

#endif // MENU_H
