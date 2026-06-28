#ifndef RASTERIZER_H
#define RASTERIZER_H

#include "projection.h"

void rasterizer_draw_triangle_vertices(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2);
void rasterizer_draw_triangle(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2);

#endif
