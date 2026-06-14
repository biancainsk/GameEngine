#include <Core/GameObject.h>
#include <Core/Renderer.h>

GameObject::GameObject(const std::string& name, Position position, Appearance appearance)
        : m_name(name), m_position(position), m_appearance(appearance)
{}

void GameObject::render(const Renderer& renderer) const
{
    renderer.drawEntity(m_position, m_appearance);
}

bool GameObject::isAlive() const
{
    return m_alive;
}

void GameObject::destroy()
{
    m_alive = false;
}

void GameObject::revive()
{
    m_alive = true;
}

int GameObject::getId() const
{
    return m_id;
}

const std::string& GameObject::getName() const
{
    return m_name;
}

Position GameObject::getPosition() const
{
    return m_position;
}

void GameObject::setPosition(Position position)
{
    m_position = position;
}

Appearance GameObject::getAppearance() const
{
    return m_appearance;
}

void GameObject::setAppearance(Appearance appearance)
{
    m_appearance = appearance;
}