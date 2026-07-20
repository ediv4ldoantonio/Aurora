#pragma once

namespace Aurora
{

    class Time
    {
        friend class Application;

    public:
        static float DeltaTime();

        static float CurrentTime();

        static void Update();

    private:
        static float s_DeltaTime;

        static float s_CurrentTime;
    };

}