#pragma once

namespace Aurora
{

    class Registry;

    class System
    {

    public:
        virtual ~System() = default;

        virtual void OnUpdate(
            Registry &registry,
            float dt)
        {
        }

        virtual void OnRender(
            Registry &registry)
        {
        }
    };

}