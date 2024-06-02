#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <mem.h>
#include "KernelManager.hpp"

class Renderer
{
public:

    Renderer(int w, int h);

    ~Renderer();

    void render2Surface(SDL_Surface* surface, int x = 0, int y = 0);

protected:

    virtual void render() = 0;

    Uint32* _pixels = nullptr;

    int _width, _height;

    SDL_PixelFormat* format = nullptr;

    KernelManager* kManager;

};

class TestRenderer : public Renderer
{
public:

    TestRenderer(int w, int h) : Renderer(w, h) {  }

protected:

    virtual void render();

};

#include "Renderer.inl"
