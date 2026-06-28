#include "transform.h"
#include <fastmath.h>


Vertex transform_rotate(Vertex v, int angle_x, int angle_y, int angle_z)
{
    Vertex result = v;

    const float scale = 1.0f / 256.0f;

    // X rotation
    float cos_x = fastmath_cos(angle_x % 360) * scale;
    float sin_x = fastmath_sin(angle_x % 360) * scale;

    float y = result.y * cos_x - result.z * sin_x;
    float z = result.y * sin_x + result.z * cos_x;

    result.y = y;
    result.z = z;


    // Y rotation
    float cos_y = fastmath_cos(angle_y % 360) * scale;
    float sin_y = fastmath_sin(angle_y % 360) * scale;

    float x = result.x * cos_y + result.z * sin_y;
    z = -result.x * sin_y + result.z * cos_y;

    result.x = x;
    result.z = z;


    // Z rotation
    float cos_z = fastmath_cos(angle_z % 360) * scale;
    float sin_z = fastmath_sin(angle_z % 360) * scale;

    x = result.x * cos_z - result.y * sin_z;
    y = result.x * sin_z + result.y * cos_z;

    result.x = x;
    result.y = y;


    return result;
}