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


// Erases everything drawn in the screen
void Renderer::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);
	SDL_RenderClear(m_renderer);
}

// Draws the content on the screen
void Renderer::present()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::drawEntity(Position pos, Size size, ShapeType shape, Color color)
{
    switch (shape)
    {
        case ShapeType::Rectangle:
        {
            drawRectangle(pos, size);
            break;
        }
        case ShapeType::Triangle:
        {
            drawTriangle(pos, size);
            break;
        }
        default:
        {
            drawRectangle(pos, size);
        }
    }
}

void Renderer::drawRectangle(Position pos, Size size)
{
    SDL_FRect rect = {pos.x, pos.y, size.width, size.height};

    // Sets the color to red (Red=0, Green=255, Blue=0, Alpha=255)
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
    SDL_RenderFillRectF(m_renderer, &rect);
}

void Renderer::drawTriangle(Position pos, Size size)
{
    SDL_FPoint points[3] = { {pos.x, pos.y},
                            {pos.x + size.width, pos.y},
                            {pos.x + size.width / 2, pos.y - size.height}
    };

    SDL_Vertex verts[3];

    verts[0].position = points[0];
    verts[1].position = points[1];
    verts[2].position = points[2];

    // Sets the color to red (Red=255, Green=0, Blue=0, Alpha=255)
    // SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
    // same color for all → filled triangle
    SDL_Color color = {255, 0, 0, 255};
    for (int i = 0; i < 3; ++i) {
        verts[i].color = color;
        verts[i].tex_coord = {0, 0}; // unused
    }
    SDL_RenderGeometry(m_renderer, nullptr, verts, 3, nullptr, 0);
}