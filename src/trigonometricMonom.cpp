#include <complex>
#include <iostream>
#include "trigonometricMonom.h"

trigonometricMonom::trigonometricMonom()
{
    //ctor
}

trigonometricMonom::~trigonometricMonom()
{
    //dtor
}

trigonometricMonom::trigonometricMonom(std::complex<float> Coefficent, phase Phase)
{
	coef = Coefficent;
	phs = Phase;
}

const trigonometricMonom trigonometricMonom::operator+()
{
	return *this;
}
const trigonometricMonom trigonometricMonom::operator-()
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
void trigonometricMonom::print()
{
	std::cout << '(' << coef.real() << " + " << coef.imag() << "i) * exp(" << phs.getOmega() << "t + " << phs.getK() << "x)";
}
