#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <Core/Globals.h>

class Window;

class Renderer
{
public:
    explicit Renderer(const Window& window);
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void clear(Color background = {20,20,20,255});
	void present();

    void drawEntity(Position pos, Appearance appearance) const; 
    void drawText(SDL_Surface* surface, Position pos) const;

private:
    void drawRectangle(Position pos, Size size, Color color) const;
    void drawTriangle(Position pos, Size size, Color color) const;
    
    SDL_Renderer* m_renderer = nullptr;
};

#endif