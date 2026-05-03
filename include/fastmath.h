#ifndef FASTMATH_H
#define FASTMATH_H

extern int sin_table[360];

void fastmath_precalc_sin();

static inline int fastmath_sin(int angle)
{
	return sin_table[angle];
}

#endif
