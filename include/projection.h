#ifndef PROJECTION_H
#define PROJECTION_H

#include "vertex.h"

typedef struct
{
    int x;
    int y;
    int light;
} ScreenVertex;

ScreenVertex projection_project_vertex(Vertex v);

#endif