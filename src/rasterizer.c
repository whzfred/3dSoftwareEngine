#include "rasterizer.h"
#include "render.h"

void rasterizer_draw_triangle_vertices(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2)
{
    render_put_pixel(v0.x, v0.y, 255, 255, 255, 255);
    render_put_pixel(v1.x, v1.y, 255, 255, 255, 255);
    render_put_pixel(v2.x, v2.y, 255, 255, 255, 255);
}

void rasterizer_draw_triangle(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2)
{
    render_put_pixel(v0.x, v0.y, 255, 255, 255, 255);
    render_put_pixel(v1.x, v1.y, 255, 255, 255, 255);
    render_put_pixel(v2.x, v2.y, 255, 255, 255, 255);
}

