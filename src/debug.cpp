#include <stdio.h>
#include "Interface/Skeleton.hpp"

int main(int argc, char *argv[])
{
    TestApp* app = TestApp::create("frsvo debug", 512, 512);
    EmptyRenderer* renderer = new EmptyRenderer(512, 512);
    app->setRenderer(renderer);
    app->loop();
    delete app;

    return 0;
}
