#include <vector>
#include <complex>
#include "trigonometricPolynomial.h"
#include "trigonometricMonom.h"

trigonometricPolynomial::trigonometricPolynomial()
{
    //ctor
}

trigonometricPolynomial::~trigonometricPolynomial()
{
    //dtor
}
void trigonometricPolynomial::addTerm(trigonometricMonom newTerm)
{
	terms.push_back(newTerm);
}
const trigonometricPolynomial trigonometricPolynomial::operator+() const
{
	return *this;
}
const trigonometricPolynomial trigonometricPolynomial::operator-() const
{
	trigonometricPolynomial out;
	for (int i = 0; i < terms.size(); i++)
	{
		out.addTerm(-(terms[i]));
	}
}
std::complex<float> trigonometricPolynomial::calculate(float t, float x)
{
	std::complex<float> result(0, 0);
	for (int i = 0; i < terms.size(); i++)
	{
		result += terms[i].calculate(t, x);
	}
	return result;
}
