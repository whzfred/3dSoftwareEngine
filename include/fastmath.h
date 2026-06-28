#ifndef FASTMATH_H
#define FASTMATH_H

#include <math.h>

extern int sin_table[360];
extern int cos_table[360];

void fastmath_precalc_sin();
void fastmath_precalc_cos();

typedef struct
{
    float x;
    float y;
    float z;
} Vec3;

static inline Vec3 vector_sub(Vec3 a, Vec3 b)
{
    Vec3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

static inline Vec3 vector_cross(Vec3 a, Vec3 b)
{
    Vec3 result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return result;
}

static inline Vec3 vector_normalize(Vec3 v)
{
    Vec3 result;

    float length = sqrtf(
        v.x * v.x +
        v.y * v.y +
        v.z * v.z
    );

    if(length == 0.0f)
    {
        result.x = 0;
        result.y = 0;
        result.z = 0;
        return result;
    }

    result.x = v.x / length;
    result.y = v.y / length;
    result.z = v.z / length;

    return result;
}

static inline float vector_dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline int fastmath_sin(int angle)
{
	return sin_table[angle];
}

static inline int fastmath_cos(int angle)
{
	return cos_table[angle];
}

#endif
