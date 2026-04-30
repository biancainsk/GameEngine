#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window
{
public:
    Window(const std::string& windowName, int windowWidth, int windowHeight);
    ~Window();

    SDL_Window* getNativeWindow() const;
    void pollEvents(bool& running);

private:
    SDL_Window* m_window = nullptr;
};

#endif