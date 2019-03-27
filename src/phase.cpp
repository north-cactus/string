#include "phase.h"

phase::phase()
{
    //ctor
}

phase::phase(float init_omeg, float init_k)
{
	omega = init_omeg;
	k = init_k;
}

phase::~phase()
{
    //dtor
}

float phase::calculate(float t, float x)
{
	return omega*t + k*x;
}

const phase operator+(const phase left, const phase right)
{
	return phase(left.omega + right.omega, left.k + right.k);
}
const phase operator-(const phase left, const phase right)
{
	return phase(left.omega - right.omega, left.k - right.k);
}
const phase operator*(const phase ph, const float coef)
{
	return phase(ph.omega*coef, ph.k*coef);
}
const phase operator*(const float coef, const phase ph)
{
	return phase(ph.omega*coef, ph.k*coef);
}

float phase::getOmega()
{
	return omega;
}
float phase::getK()
{
	return k;
}
