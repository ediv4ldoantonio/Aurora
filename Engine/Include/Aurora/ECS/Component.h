#pragma once

#include <cstdint>
#include <atomic>

namespace Aurora
{

    using ComponentType = uint32_t;

    inline ComponentType GetUniqueComponentTypeID()
    {
        static ComponentType lastID = 0;

        return lastID++;
    }

    template <typename T>
    ComponentType GetComponentTypeID()
    {
        static ComponentType typeID =
            GetUniqueComponentTypeID();

        return typeID;
    }

}