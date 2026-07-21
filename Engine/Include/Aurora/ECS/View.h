#pragma once

#include <vector>

namespace Aurora
{

    template <typename... Components>
    class View
    {

    public:
        View(
            Registry *registry)
            : m_Registry(registry)
        {
        }

        class Iterator
        {
        };

    private:
        Registry *m_Registry;
    };

}