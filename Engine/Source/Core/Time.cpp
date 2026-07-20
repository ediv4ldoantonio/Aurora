#include <Aurora/Core/Time.h>

namespace Aurora
{

    float Time::s_DeltaTime = 0.0f;

    float Time::s_CurrentTime = 0.0f;

    float Time::DeltaTime()
    {
        return s_DeltaTime;
    }

    float Time::CurrentTime()
    {
        return s_CurrentTime;
    }

}