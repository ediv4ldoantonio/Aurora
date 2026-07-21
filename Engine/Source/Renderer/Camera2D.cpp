#include "Aurora/Renderer/Camera2D.h"

namespace Aurora
{

    Camera2D::Camera2D()
    {
    }

    void Camera2D::SetPosition(
        const Vector2 &position)
    {
        m_Position = position;
    }

    const Vector2 &
    Camera2D::GetPosition() const
    {
        return m_Position;
    }

    Vector2 Camera2D::WorldToScreen(
        const Vector2 &worldPosition) const
    {

        return worldPosition - m_Position;
    }

}