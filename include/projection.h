#ifndef PROJECTION_H
#define PROJECTION_H

#include "vertex.h"

typedef struct
{
    int x;
    int y;
} ScreenVertex;

ScreenVertex projection_project_vertex(Vertex v);

#endif