#pragma once

#include <cstdint>

namespace Aurora
{

    class UUID
    {
    public:
        UUID();

        explicit UUID(uint64_t uuid);

        operator uint64_t() const
        {
            return m_UUID;
        }

    private:
        uint64_t m_UUID;
    };

}