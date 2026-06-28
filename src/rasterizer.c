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

void rasterizer_draw_triangle(ScreenVertex v0, ScreenVertex v1, ScreenVertex v2)
{
    // Sort vertices by Y
    if(v0.y > v1.y)
    {
      rasterizer_swap_screen_vertex(&v0, &v1);
    }

    if(v0.y > v2.y)
    {
        rasterizer_swap_screen_vertex(&v0, &v2);
    }
    
    if(v1.y > v2.y)
    {
        rasterizer_swap_screen_vertex(&v1, &v2);
    }
   
    int light = (v0.light + v1.light + v2.light) / 3;

    // Long edge: v0 -> v2
    float x02 = v0.x;
    float dx02 = 0.0f;

    if(v2.y - v0.y > 0)
    {
        dx02 = (float)(v2.x - v0.x) / (v2.y - v0.y);
    }

    // Upper edge: v0 -> v1
    float x01 = v0.x;
    float dx01 = 0.0f;

    if(v1.y - v0.y > 0)
    {
        dx01 = (float)(v1.x - v0.x) / (v1.y - v0.y);
    }

    // Upper half
    for(int y = v0.y; y < v1.y; y++)
    {
        int start = (int)x01;
        int end   = (int)x02;

        if(start > end)
        {
            int tmp = start;
            start = end;
            end = tmp;
        }

       
         render_draw_line(start, end, y, light, light, light, 255);
      

        x01 += dx01;
        x02 += dx02;
    }

    // Lower edge: v1 -> v2
    float x12 = v1.x;
    float dx12 = 0.0f;

    if(v2.y - v1.y > 0)
    {
        dx12 = (float)(v2.x - v1.x) / (v2.y - v1.y);
    }

    // Lower half
    for(int y = v1.y; y <= v2.y; y++)
    {
        int start = (int)x12;
        int end   = (int)x02;

        if(start > end)
        {
            int tmp = start;
            start = end;
            end = tmp;
        }

        render_draw_line(start, end, y, light, light, light, 255);

        x12 += dx12;
        x02 += dx02;
    }
}
