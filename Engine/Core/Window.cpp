#include <Core/Window.h>

#include <stdexcept>

Window::Window(const std::string& windowName, int windowWidth, int windowHeight)
                : m_windowWidth(windowWidth), m_windowHeight(windowHeight)
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow(windowName.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                windowWidth,
                                windowHeight,
                                SDL_WINDOW_SHOWN);

    if (!m_window)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Window::~Window()
{
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

SDL_Window* Window::getNativeWindow() const
{
    return m_window;
}

void Window::pollEvents(bool& running)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

int Window::getWindowWidth() const
{
    return m_windowWidth;
}

int Window::getWindowHeight() const
{
    return m_windowHeight;
}