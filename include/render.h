#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include "config.h"
#include "object.h"

extern Uint32 pixels[WIDTH * HEIGHT];

void render_object(Object* obj, int angle_x, int angle_y, int angle_z);
void render_triangle();

static inline void render_put_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    pixels[y * WIDTH + x] = (r << 24) | (g << 16) | (b << 8) | a;
}

#endif
