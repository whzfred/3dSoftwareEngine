#include "projection.h"
#include "config.h"

static int fov = 300;

ScreenVertex projection_project_vertex(Vertex v)
{
    ScreenVertex result;

    result.x = (int)((v.x * fov) / v.z) + WIDTH / 2;
    result.y = HEIGHT / 2 - (int)((v.y * fov) / v.z);

    result.light = 255 - (v.z * 10);

    if(result.light < 20)
    {
        result.light = 20;
    }

    if(result.light > 255)
    {
        result.light = 255;
    }

    return result;
}