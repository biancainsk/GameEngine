#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include <Core/Window.h>
#include <Core/Renderer.h>
#include <Systems/InputManager.h>
#include <Systems/CollisionSystem.h>

class IGame;

class Engine
{
public:
    Engine(const std::string& windowName, int windowWidth, int windowHeight);

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    void run(IGame& game);

private:
    Window m_window;
	Renderer m_renderer;
    InputManager m_inputManager;
    CollisionSystem m_collisionSystem;
};

#endif