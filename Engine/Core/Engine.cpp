#include <Core/Engine.h>
#include <Core/IGame.h>

#include <cstdint>

Engine::Engine(const std::string& windowName, int windowWidth, int windowHeight)
            : m_window(windowName, windowWidth, windowHeight),
              m_renderer(m_window)
{}

void Engine::run(IGame& game)
{
    game.initialize(Size{m_window.getWindowWidth(), m_window.getWindowHeight()});
    std::uint64_t lastTime = SDL_GetTicks64();

    while (m_isRunning)
    {
        std::uint64_t currentTime = SDL_GetTicks64();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        // Step 1: Poll/pump SDL events
        m_isRunning = m_window.pollEvents();
        if (!m_isRunning)
        {
            break;
        }

        // Step 2: Read current keyboard state
        m_inputManager.update();
        
        // Step 3: Update game using the input
        game.update(dt, m_inputManager, m_collisionSystem);

        // Step 4: Render
        // Rendering steps: 1) Clear previous frame -> 2) Draw current frame -> 3) Show current frame
        m_renderer.clear();
        game.render(m_renderer);
        m_renderer.present();
    }
}

