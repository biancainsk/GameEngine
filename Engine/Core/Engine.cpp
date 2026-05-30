#include <Core/Engine.h>
#include <Core/IGame.h>

#include <cstdint>

Engine::Engine(const std::string& windowName, int windowWidth, int windowHeight)
            : m_window(windowName, windowWidth, windowHeight),
              m_renderer(m_window)
{}

void Engine::run(IGame& game)
{
    game.initialize(m_window.getWindowWidth(), m_window.getWindowHeight());
    std::uint64_t lastTime = SDL_GetTicks64();

    while (m_isRunning)
    {
        uint32_t currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        m_isRunning = m_window.pollEvents();
        m_inputManager.update();
        game.update(dt, m_inputManager);

        m_renderer.clear();
        game.render(m_renderer);
        m_renderer.present();
    }
}

