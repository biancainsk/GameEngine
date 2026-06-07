#include <Core/Renderer.h>
#include <Core/Window.h>

#include <stdexcept>

Renderer::Renderer(const Window& window)
{
    m_renderer = SDL_CreateRenderer(window.getNativeWindow(),
                                    -1,
                                    SDL_RENDERER_ACCELERATED);

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

void Renderer::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);
	SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::drawEntity(Position pos, Size size, ShapeType shape, Color color) const
{
    switch (shape)
    {
        case ShapeType::Rectangle:
        {
            drawRectangle(pos, size, color);
            break;
        }
        case ShapeType::Triangle:
        {
            drawTriangle(pos, size, color);
            break;
        }
        default:
        {
            drawRectangle(pos, size, color);
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

    SDL_Color _color = {color.r, color.g, color.b, color.a};
    for (int i = 0; i < 3; ++i) {
        verts[i].color = _color;
    }
    SDL_RenderGeometry(m_renderer, nullptr, verts, 3, nullptr, 0);
}