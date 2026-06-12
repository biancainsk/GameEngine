#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window
{
public:
    Window(const std::string& windowName, int windowWidth, int windowHeight);
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    SDL_Window* getNativeWindow() const;
    bool pollEvents();

    int getWindowWidth() const;
    int getWindowHeight() const;

private:
    int m_windowWidth = 0;
    int m_windowHeight = 0;

    SDL_Window* m_window = nullptr;
};

#endif