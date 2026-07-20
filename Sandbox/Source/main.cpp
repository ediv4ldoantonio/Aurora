#include <Aurora/Core/Application.h>
#include "SandboxLayer.h"
#include <memory>

int main()
{

    Aurora::Application app;

    app.PushLayer(
        std::make_unique<SandboxLayer>());

    app.Run();

    return 0;
}