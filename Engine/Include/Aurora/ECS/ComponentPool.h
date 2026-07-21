#pragma once

#include <unordered_map>
#include <utility>

namespace Aurora
{

    class IComponentPool
    {

    public:
        virtual ~IComponentPool() = default;
    };

    template <typename T>
    class ComponentPool : public IComponentPool
    {

    public:
        template <typename... Args>
        T &Add(
            EntityID entity,
            Args &&...args)
        {

            m_Entities.push_back(entity);

            auto [iterator, inserted] =
                m_Data.emplace(
                    entity,
                    T(std::forward<Args>(args)...));

            return iterator->second;
        }

        T &Get(
            EntityID entity)
        {

            return m_Data.at(entity);
        }

        bool Has(
            EntityID entity) const
        {

            return m_Data.contains(entity);
        }

    private:
        std::unordered_map<EntityID, T> m_Data;

        std::vector<EntityID> m_Entities;
    };

}