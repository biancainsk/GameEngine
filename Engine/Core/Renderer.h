#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <Core/Globals.h>

class Window;

class Renderer
{
public:
    Renderer(const Window& window);
    ~Renderer();

    void clear();
	void present();

    void drawEntity(Position pos, Size size, ShapeType shape, Color color);  
    void drawRectangle(Position pos, Size size);
    void drawTriangle(Position pos, Size size);

private:
    SDL_Renderer* m_renderer = nullptr;
};

#endif