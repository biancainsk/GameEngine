#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "Globals.h"

class Window;

class Renderer
{
public:
    Renderer(const Window& window);
    ~Renderer();

    void clear();
	void present();
    
    void drawRectangle(Position pos, Size size);
    void drawTriangle(Position pos, Size size);

    // SDL_Renderer* renderer() const { return m_renderer; }

private:
    SDL_Renderer* m_renderer = nullptr;
};

#endif