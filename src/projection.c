#include "projection.h"
#include "config.h"

static int fov = 300;

void projection_project_vertex(Vertex v, int* x, int* y)
{
    *x = (int)((v.x * fov) / v.z) + WIDTH / 2;
    *y = HEIGHT / 2 - (int)((v.y * fov) / v.z);
}