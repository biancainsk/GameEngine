#include <Core/Renderer.h>
#include <Core/Window.h>

#include <stdexcept>
#include <cassert>

Renderer::Renderer(const Window& window)
{
    m_renderer = SDL_CreateRenderer(window.getNativeWindow(),
                                    -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!m_renderer)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Renderer::~Renderer()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

void Renderer::clear(Color background)
{
	SDL_SetRenderDrawColor(m_renderer, background.r, background.g, background.b, background.a);
	SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::drawEntity(Position pos, Appearance appearance) const
{
    switch (appearance.shape)
    {
        case ShapeType::Rectangle:
        {
            drawRectangle(pos, appearance.size, appearance.color);
            break;
        }
        case ShapeType::Triangle:
        {
            drawTriangle(pos, appearance.size, appearance.color);
            break;
        }
        default:
        {
            assert(false && "Unhandled ShapeType");
        }
    }
}

void Renderer::drawRectangle(Position pos, Size size, Color color) const
{
    SDL_FRect rect = {pos.x - size.width / 2.0f, pos.y - size.height / 2.0f, static_cast<float>(size.width), static_cast<float>(size.height)};

    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRectF(m_renderer, &rect);
}

void Renderer::drawTriangle(Position pos, Size size, Color color) const
{
    SDL_FPoint points[3] = {{pos.x, pos.y - size.height / 2.0f},
                            {pos.x - size.width / 2.0f, pos.y + size.height / 2.0f},
                            {pos.x + size.width / 2.0f, pos.y + size.height / 2.0f}
    };

    SDL_Vertex verts[3];

    verts[0].position = points[0];
    verts[1].position = points[1];
    verts[2].position = points[2];

    SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
    for (int i = 0; i < 3; ++i)
    {
        verts[i].color = sdlColor;
    }
    SDL_RenderGeometry(m_renderer, nullptr, verts, 3, nullptr, 0);
}

void Renderer::drawText(SDL_Surface* surface, Position pos) const
{
    if (!surface)
    {
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture)
    {
        return;
    }

    SDL_Rect rect = {static_cast<int>(pos.x), static_cast<int>(pos.y),
                     surface->w, surface->h};
    SDL_RenderCopy(m_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}