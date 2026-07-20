#include <Aurora/Core/Application.h>
#include "SandboxLayer.h"

int main()
{

    Aurora::Application app;

    app.PushLayer(
        new SandboxLayer());

    app.Run();

    return 0;
}