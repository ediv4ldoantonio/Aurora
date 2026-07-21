#pragma once

namespace Aurora
{

    template <typename... Components>
    std::vector<Entity>
    View<Components...>::GetEntities()
    {

        std::vector<Entity> result;

        for (auto id :
             m_Registry->GetEntities())
        {

            Entity entity(
                id,
                m_Registry);

            if (
                HasAllComponents<Components...>(entity))
            {
                result.push_back(entity);
            }
        }

        return result;
    }

}