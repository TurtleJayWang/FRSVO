#pragma once

#include <iostream>
#include <cmath>
#include <cstdint>

#include <glm/glm.hpp>

class Voxel
{
public:

    Voxel();

    ~Voxel();

    static uint8_t pos2idx(uint8_t x, uint8_t y, uint8_t z) { return (x | y << 1 | z << 2); }

    static void idx2pos(uint8_t* x, uint8_t* y, uint8_t* z, uint8_t idx);

private:

    uint8_t index;

    uint8_t scale;

    glm::vec4 color;

    glm::vec3 position;

};

void Voxel::idx2pos(uint8_t* x, uint8_t* y, uint8_t* z, uint8_t idx)
{
    *x = idx & 1; *y = (idx & 2) >> 1; *z = (idx & 4) >> 2;
}
