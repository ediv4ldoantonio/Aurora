#pragma once

#include <vector>
#include <memory>

#include "Aurora/ECS/System.h"

namespace Aurora
{

    class Registry;

    class SystemManager
    {

    public:
        template <typename T, typename... Args>
        T &AddSystem(
            Args &&...args)
        {

            auto system =
                std::make_unique<T>(
                    std::forward<Args>(args)...);

            T &reference =
                *system;

            m_Systems.push_back(
                std::move(system));

            return reference;
        }

        void Update(
            Registry &registry,
            float dt);

        void Render(
            Registry &registry);

    private:
        std::vector<
            std::unique_ptr<System>>
            m_Systems;
    };

}