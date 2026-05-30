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
    bool pollEvents();

    int getWindowWidth() const;
    int getWindowHeight() const;

private:
    SDL_Window* m_window = nullptr;

    int m_windowWidth;
    int m_windowHeight;
};

#endif