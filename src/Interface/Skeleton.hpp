#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "Renderer.hpp"

class TestApp
{
public:

    ~TestApp();

    void loop();

    void setRenderer(Renderer* renderer) { _renderer = renderer; }

    static TestApp* create(const char* title, int w, int h, int flags = SDL_WINDOW_SHOWN);

private:

    TestApp() = default;

    std::string _title;

    int _width, _height;

    int flags = SDL_WINDOW_SHOWN;

    bool _running = true;

    static bool haveCreatedOneInstance;

    SDL_Window* window = nullptr;

    SDL_Surface* windowSurface = nullptr;

    SDL_PixelFormat* format = nullptr;

    Renderer* _renderer = nullptr;

};

#include "Skeleton.inl"
