#include "Engine.h"
#include "IGame.h"
#include "Window.h"
#include "Renderer.h"
#include "../Systems/InputManager.h"
#include "../Systems/CollisionSystem.h"

Engine::Engine(const std::string& windowName, int windowWidth, int windowHeight)
{
    m_window = new Window(windowName, windowWidth, windowHeight);
    m_renderer = new Renderer(*m_window);
    m_inputManager = new InputManager();
    m_collisionSystem = new CollisionSystem();
}

Engine::~Engine()
{
    delete m_renderer;
    delete m_window;
    delete m_inputManager;
    delete m_collisionSystem;
}

void Engine::run(IGame& game)
{
    uint32_t lastTime = SDL_GetTicks();

    while (m_isRunning)
    {
        uint32_t currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        m_window->pollEvents(m_isRunning);
        m_inputManager->update();
        game.update(dt, *m_inputManager);

        m_renderer->clear();
        game.render(*m_renderer);
        m_renderer->present();
    }
}

