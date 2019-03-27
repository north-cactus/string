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
void trigonometricMonom::print()
{
	std::cout << '(' << coef.real() << " + " << coef.imag() << "i) * exp(" << phs.getOmega() << "t + " << phs.getK() << "x)";
}