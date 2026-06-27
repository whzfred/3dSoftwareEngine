#ifndef CAMERA_H
#define CAMERA_H

#include "vertex.h"

typedef struct
{
    float x;
    float y;
    float z;

} Camera;

extern Camera camera;

Vertex camera_transform(Vertex v, Camera* cam);

#endif