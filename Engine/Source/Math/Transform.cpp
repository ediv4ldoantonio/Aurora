#include "Aurora/Math/Transform.h"

namespace Aurora
{

    Transform::Transform(
        const Vector2 &position,
        float rotation,
        const Vector2 &scale)
        : Position(position),
          Rotation(rotation),
          Scale(scale)
    {
    }

}