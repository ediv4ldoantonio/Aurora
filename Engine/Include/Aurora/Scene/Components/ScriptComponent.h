#pragma once

#include "Aurora/Scene/Components/Component.h"
#include "Aurora/Scene/Entity.h"
#include "Scriptable.h"

namespace Aurora
{
    struct ScriptComponent : public Component
    {
        Scriptable *Instance = nullptr;
    };

}