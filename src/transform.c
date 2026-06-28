#include "transform.h"
#include <fastmath.h>


Vertex transform_rotate(Vertex v, int angle_x, int angle_y, int angle_z)
{
    // Todo implement fixed point
    Vertex result = v;

    const float scale = 1.0f / 256.0f;

    // X rotation
    float cos_x = fastmath_cos(angle_x % 360) * scale;
    float sin_x = fastmath_sin(angle_x % 360) * scale;

    float y = result.pos.y * cos_x - result.pos.z * sin_x;
    float z = result.pos.y * sin_x + result.pos.z * cos_x;

    result.pos.y = y;
    result.pos.z = z;

    // Y rotation
    float cos_y = fastmath_cos(angle_y % 360) * scale;
    float sin_y = fastmath_sin(angle_y % 360) * scale;

    float x = result.pos.x * cos_y + result.pos.z * sin_y;
    z = -result.pos.x * sin_y + result.pos.z * cos_y;

    result.pos.x = x;
    result.pos.z = z;

    // Z rotation
    float cos_z = fastmath_cos(angle_z % 360) * scale;
    float sin_z = fastmath_sin(angle_z % 360) * scale;

    x = result.pos.x * cos_z - result.pos.y * sin_z;
    y = result.pos.x * sin_z + result.pos.y * cos_z;

    result.pos.x = x;
    result.pos.y = y;

    return result;
}