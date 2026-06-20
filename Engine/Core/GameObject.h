#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Core/Globals.h>
#include <string>

class Renderer;

class GameObject
{
public:
    GameObject() = delete;
    explicit GameObject(const std::string& name, Position position, Appearance appearance);
    virtual ~GameObject() = default;
    GameObject(const GameObject&) = delete;
    GameObject& operator=(const GameObject&) = delete;

    virtual void update(float dt) = 0;
    virtual void render(const Renderer& renderer) const;

    bool isAlive() const;
    void destroy();

    int getId() const;
    const std::string& getName() const;

    Position getPosition() const;
    void setPosition(Position position);

    Appearance getAppearance() const;
    void setAppearance(Appearance appearance);

protected:
    void revive();

private:
    inline static int s_nextId = 0;

    int m_id = ++s_nextId;
    std::string m_name;
    bool m_alive = true;

    Position m_position;
    Appearance m_appearance;
};

#endif