#include <complex>
#include <iostream>
#include "trigonometricMonom.h"

trigonometricMonom::trigonometricMonom()
{
    //ctor
}
trigonometricMonom::trigonometricMonom(std::complex<float> Coefficent, phase Phase)
{
	coef = Coefficent;
	phs = Phase;
}
trigonometricMonom::~trigonometricMonom()
{
    //dtor
}
std::complex<float> trigonometricMonom::calculate(float t, float x)
{
	return coef * exp(std::complex<float>(0, 1) * phs.calculate(t, x));
}
const trigonometricMonom trigonometricMonom::operator+() const
{
	return *this;
}
const trigonometricMonom trigonometricMonom::operator-() const
{
	return trigonometricMonom(-coef, phs);
}
const trigonometricMonom operator*(const trigonometricMonom left, const trigonometricMonom right)
{
	return trigonometricMonom(left.coef * right.coef, left.phs + right.phs);
}
const trigonometricMonom operator*(const std::complex<float> left, const trigonometricMonom right)
{
	return trigonometricMonom(left * right.coef, right.phs);
}
const trigonometricMonom operator*(const trigonometricMonom left,const std::complex<float> right)
{
	return trigonometricMonom(left.coef * right, left.phs);
}
const trigonometricMonom operator/(const trigonometricMonom left, const trigonometricMonom right)
{
	return trigonometricMonom(left.coef / right.coef, left.phs - right.phs);
}
const trigonometricMonom operator/(const std::complex<float> left, const trigonometricMonom right)
{
	return trigonometricMonom(left / right.coef, -right.phs);
}
const trigonometricMonom operator/(const trigonometricMonom left,const std::complex<float> right)
{
	return trigonometricMonom(left.coef / right, left.phs);
}
void trigonometricMonom::print()
{
	std::cout << '(' << coef.real() << " + " << coef.imag() << "i) * exp(" << phs.getOmega() << "t + " << phs.getK() << "x)";
}
