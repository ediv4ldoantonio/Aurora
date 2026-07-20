#include <Aurora/Core/Time.h>
#include <chrono>

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

    void Time::Update()
    {
        using namespace std::chrono;

        static auto startTime =
            high_resolution_clock::now();

        static auto lastTime = startTime;

        auto currentTime =
            high_resolution_clock::now();

        float delta =
            duration<float>(
                currentTime - lastTime)
                .count();

        Time::s_DeltaTime = delta;
        Time::s_CurrentTime = duration<float>(
                                  currentTime - startTime)
                                  .count();

        lastTime = currentTime;
    }
}