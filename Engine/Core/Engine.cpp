#include <Core/Engine.h>
#include <Core/IGame.h>

#include <SDL2/SDL.h>
#include <cstdint>
#include <algorithm>

// cap dt so a frozen/lagging frame doesn't blow up physics ( ~20 FPS minimum)
static constexpr float MAX_DT = 0.05f;

Engine::Engine(const std::string& windowName, int windowWidth, int windowHeight)
            : m_window(windowName, windowWidth, windowHeight),
              m_renderer(m_window)
{}

void Engine::run(IGame& game)
{
    game.initialize(Size{m_window.getWindowWidth(), m_window.getWindowHeight()});
    std::uint64_t lastTime = SDL_GetTicks64();

    // Step 1: Poll/pump SDL events
    while (m_window.pollEvents())
    {
        std::uint64_t currentTime = SDL_GetTicks64();
        // dt = how many seconds passed since the last frame
        const float dt = std::min(static_cast<float>((currentTime - lastTime) / 1000.0f), MAX_DT);
        lastTime = currentTime;

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

