#ifndef FASTMATH_H
#define FASTMATH_H

extern int sin_table[360];
extern int cos_table[360];

void fastmath_precalc_sin();
void fastmath_precalc_cos();

static inline int fastmath_sin(int angle)
{
	return sin_table[angle];
}

static inline int fastmath_cos(int angle)
{
	return cos_table[angle];
}

#endif
