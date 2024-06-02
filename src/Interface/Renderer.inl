#include "Renderer.hpp"

Renderer::Renderer(int w, int h) : _width(w), _height(h) 
{
    _pixels = (Uint32*) malloc(sizeof(Uint32) * w * h);
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
            _pixels[y * w + x] = 0x000000;
    std::cout << std::hex << _pixels[w * h - 1] << std::endl;
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
    /*
    //For test
    auto image = IMG_Load("steamHead.jpg");
    if (image == nullptr)
    {
        std::cout << "Fail to load image" << std::endl;
        return;
    }
    SDL_BlitSurface(image, NULL, surface, NULL);*/
    
    SDL_LockSurface(surface);

    Uint32* pixels = (Uint32*)surface->pixels;
    memcpy(pixels, _pixels, sizeof(Uint32) * _width * _height);

    SDL_UnlockSurface(surface);
}

void TestRenderer::render()
{
    
}
