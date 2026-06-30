#include <Core/TextRenderer.h>
#include <Core/Renderer.h>
#include <stdexcept>

TextRenderer::TextRenderer(const std::string& fontPath, int fontSize)
{
    if (TTF_Init() != 0)
    {
        throw std::runtime_error(TTF_GetError());
    }

    m_font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!m_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

TextRenderer::~TextRenderer()
{
    if (m_font)
    {
        TTF_CloseFont(m_font);
    }
    TTF_Quit();
}

void TextRenderer::draw(const Renderer& renderer, const std::string& text,
                        Position pos, Color color) const
{
    SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
    SDL_Surface* surface = TTF_RenderText_Blended(m_font, text.c_str(), sdlColor);
    if (!surface)
    {
        return;
    }

    renderer.drawText(surface, pos);
    SDL_FreeSurface(surface);
}