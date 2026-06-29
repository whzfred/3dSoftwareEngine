#include "rasterizer.h"
#include "render.h"
#include <stdio.h>
#include "fastmath.h"

void rasterizer_draw_triangle_vertices(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2)
{
    render_put_pixel(v0.x, v0.y, 255, 255, 255, 255);
    render_put_pixel(v1.x, v1.y, 255, 255, 255, 255);
    render_put_pixel(v2.x, v2.y, 255, 255, 255, 255);
}

static inline void rasterizer_sort_span(int *start, int *end)
{
    if(*start > *end)
    {
        int tmp = *start;
        *start = *end;
        *end = tmp;
    }
}

static void rasterizer_draw_top_triangle(ScreenVertex v0, ScreenVertex v1,  ScreenVertex v2, int light)
{
    float x02 = v0.x;
    float x01 = v0.x;
    float dx02 = (float)(v2.x - v0.x) / (v2.y - v0.y);
    float dx01 = (float)(v1.x - v0.x) / (v1.y - v0.y);

    for(int y = v0.y; y < v1.y; y++)
    {
        int start = (int)x01;
        int end   = (int)x02;

        rasterizer_sort_span(&start, &end);
        render_draw_line(start, end, y, light, light, light, 255);

        x01 += dx01;
        x02 += dx02;
    }
}

static void rasterizer_draw_bottom_triangle(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2, int light)
{
    float x02 = v0.x;
    float x12 = v1.x;
    float dx02 = (float)(v2.x - v0.x) / (v2.y - v0.y);
    float dx12 = (float)(v2.x - v1.x) / (v2.y - v1.y);

    x02 += dx02 * (v1.y - v0.y);

    for(int y = v1.y; y < v2.y; y++)
    {
        int start = (int)x12;
        int end   = (int)x02;

        rasterizer_sort_span(&start, &end);
        render_draw_line(start, end, y, light, light, light, 255);

        x12 += dx12;
        x02 += dx02;
    }
}

void rasterizer_draw_triangle(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2)
{
    // Sort by y
    if(v0.y > v1.y)
        rasterizer_swap_screen_vertex(&v0, &v1);

    if(v0.y > v2.y)
        rasterizer_swap_screen_vertex(&v0, &v2);

    if(v1.y > v2.y)
        rasterizer_swap_screen_vertex(&v1, &v2);

    // check if triangle has zero height and in that case skip
    if(v0.y == v2.y)
    {
        return;
    }

    int light = (v0.light + v1.light + v2.light) / 3;

    if(v1.y != v0.y)
        rasterizer_draw_top_triangle(v0, v1, v2, light);

    if(v1.y != v2.y)
        rasterizer_draw_bottom_triangle(v0, v1, v2, light);
}
