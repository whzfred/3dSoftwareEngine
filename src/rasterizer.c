#include "rasterizer.h"
#include "render.h"

void rasterizer_draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    render_put_pixel(x1,y1,255,255,255,255);
    render_put_pixel(x2,y2,255,255,255,255);
    render_put_pixel(x3,y3,255,255,255,255);
}