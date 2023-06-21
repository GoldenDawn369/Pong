#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    void clear() const;
    void update() const;
    bool isClosed() const;

    SDL_Renderer* getRenderer() const;

private:
    bool closed = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool init();
};

#endif // WINDOW_H
