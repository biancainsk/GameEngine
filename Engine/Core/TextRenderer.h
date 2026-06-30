#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include <Core/Globals.h>

class Renderer;

class TextRenderer
{
public:
    TextRenderer(const std::string& fontPath, int fontSize);
    ~TextRenderer();
    TextRenderer(const TextRenderer&) = delete;
    TextRenderer& operator=(const TextRenderer&) = delete;

    void draw(const Renderer& renderer, const std::string& text, Position pos, Color color) const;

private:
    TTF_Font* m_font = nullptr;
};

#endif