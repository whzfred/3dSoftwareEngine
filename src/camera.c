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
    result.x = v.x - cam->x;
    result.y = v.y - cam->y;
    result.z = v.z - cam->z;
    return result;
}