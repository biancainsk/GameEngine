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

    void drawEntity(Position pos, Size size, ShapeType shape, Color color) const;  
    void drawRectangle(Position pos, Size size, Color color) const;
    void drawTriangle(Position pos, Size size, Color color) const;

private:
    SDL_Renderer* m_renderer = nullptr;
};

#endif