#include "camera.h"

Camera camera =
{
    0.0f,
    0.0f,
    -5.0f
};

Vertex camera_transform(Vertex v, Camera* cam)
{
    Vertex result;
    result.pos.x = v.pos.x - cam->x;
    result.pos.y = v.pos.y - cam->y;
    result.pos.z = v.pos.z - cam->z;
    return result;
}