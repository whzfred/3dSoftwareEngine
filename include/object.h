#ifndef OBJECT_H
#define OBJECT_H

#include "vertex.h"
#include "face.h"

typedef struct
{
    Vertex* vertices;
    int vertex_count;

    Face* faces;
    int face_count;
} Object;

#endif
