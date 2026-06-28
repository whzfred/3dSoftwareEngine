#include "projection.h"
#include "config.h"

static int fov = 300;

ScreenVertex projection_project_vertex(Vertex v)
{
    ScreenVertex result;

    float z_depth = v.pos.z;
    if (z_depth == 0.0f) 
    {
        z_depth = 0.001f; 
    }

    float aspect_ratio = (float)WIDTH / (float)HEIGHT;
    result.x = (int)((v.pos.x * (float)fov) / (z_depth * aspect_ratio)) + WIDTH / 2;
    result.y = HEIGHT / 2 - (int)((v.pos.y * (float)fov) / z_depth);
   
    return result;
}