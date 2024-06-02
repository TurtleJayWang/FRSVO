#include "Renderer.hpp"

Renderer::Renderer(int w, int h) : _width(w), _height(h) 
{
    _pixels = (Uint32*) malloc(sizeof(Uint32) * w * h);
    memset(_pixels, 0xffffff, sizeof(Uint32) * w * h);
}

Renderer::~Renderer()
{
    free(_pixels);
}

void Renderer::render2Surface(SDL_Surface* surface, int x, int y)
{
    format = surface->format;
    SDL_Rect renderRect = { x, y, _width, _height };

    render();

    SDL_LockSurface(surface);

    Uint32* pixels = (Uint32*)surface->pixels;
    memcpy(pixels, _pixels, sizeof(Uint32) * _width * _height);

    SDL_UnlockSurface(surface);
}
