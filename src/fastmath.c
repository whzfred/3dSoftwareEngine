#include <math.h>
#include "fastmath.h"

#define PI 3.14159265358979323846f

int sin_table[360];

void fastmath_precalc_sin()
{
    const float deg_to_rad = PI / 180.0f;

    for (int i = 0; i < 360; i++)
    {
         sin_table[i] = (int)(sinf(i * deg_to_rad) * (1 << 8));
    }
} 

