#include "Skeleton.hpp"
#include <bitset>
#include <SDL2/SDL_image.h>

bool TestApp::haveCreatedOneInstance = false;

TestApp* TestApp::create(const char* title, int w, int h, int flags)
{
    if (haveCreatedOneInstance)
    {
        std::cerr << "You have already created one instance!" << std::endl;
        return nullptr;
    }

    haveCreatedOneInstance = true;

    TestApp* app = new TestApp;
    app->_title = title; 
    app->_width = w; app->_height = h; 
    app->flags = flags;

    SDL_Init(SDL_INIT_EVERYTHING);

    app->window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        w, h,
        flags
    );
    if (app->window == nullptr) 
    {
        std::cerr << "Fail to create window!" << std::endl;
        delete app;
        return nullptr;
    }

    app->windowSurface = SDL_GetWindowSurface(app->window);
    if (app->windowSurface == nullptr)
    {
        std::cerr << "Fail to create window!" << std::endl;
        delete app;
        return nullptr;
    }

    app->format = app->windowSurface->format;
    std::cout << "Format: " << app->format->format << std::endl;
    std::cout << "Bytes Per pixel: " << int(app->format->BytesPerPixel) << std::endl;
    std::cout << "RGBmask: " << std::hex
        << app->format->Rmask << " " 
        << app->format->Gmask << " " 
        << app->format->Bmask << " "
        << app->format->Amask << std::endl;

    std::cout << "RGBshift: " << std::dec
        << int(app->format->Rshift) << " " 
        << int(app->format->Gshift) << " " 
        << int(app->format->Bshift) << " "
        << int(app->format->Ashift) << std::endl;

    std::cout << "RGBloss: " << std::dec
        << int(app->format->Rloss) << " " 
        << int(app->format->Gloss) << " " 
        << int(app->format->Bloss) << " "
        << int(app->format->Aloss) << std::endl;

    return app;
}

void TestApp::loop()
{
    while (_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                _running = false;
                break;
            
            default:
                break;
            }
        }

        _renderer->render2Surface(windowSurface, _width, _height);

        SDL_UpdateWindowSurface(window);
    }
}

TestApp::~TestApp()
{
    SDL_DestroyWindow(window);
    SDL_FreeSurface(windowSurface);
}
