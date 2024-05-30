#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class TestApp
{
public:

    void loop();

    void setOpenGL(bool flag);

    static TestApp* createDefaultSize(const char* title);

    static TestApp* create(const char* title, int w, int h);

protected:

    void render();

private:

    TestApp();

    std::string _title;

    int _width, _height;

    int flags;

};

#include "Skeleton.inl"
