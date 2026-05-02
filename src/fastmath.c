#include "fastmath.h"
#include <math.h>

#define PI 3.14159265358979323846f

static int sin_table[360];

void fastmath_precal_sin()
{
	for (int i = 0; i < 360; i++)
    {    
	    sin_table[i] = (int)(sinf(i * (PI / 180.0f)) * (1 << 8));
    }
} 

int fastmath_sin(int angle)
{
	return sin_table[angle];
}