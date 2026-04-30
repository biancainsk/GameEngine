#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <string>

class Window;
class Renderer;
class InputManager;
class CollisionSystem;
class IGame;

class Engine
{
public:
    Engine(const std::string& windowName, int windowWidth, int windowHeight);
    ~Engine();

    void run(IGame& game);

private:
    Window* m_window = nullptr;
	Renderer* m_renderer = nullptr;
    InputManager* m_inputManager = nullptr;
    CollisionSystem* m_collisionSystem = nullptr;

    bool m_isRunning = true;
};

#endif