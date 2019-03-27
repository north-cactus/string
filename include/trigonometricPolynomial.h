#ifndef TRIGONOMETRICPOLYNOMIAL_H
#define TRIGONOMETRICPOLYNOMIAL_H
#include <vector>
#include <complex>
#include "phase.h"
#include "trigonometricMonom.h"
class trigonometricPolynomial
{
	public:
		trigonometricPolynomial();
		virtual ~trigonometricPolynomial();
		const trigonometricPolynomial operator+() const;
		const trigonometricPolynomial operator-() const;
		friend const trigonometricPolynomial operator+(const trigonometricPolynomial left, const trigonometricPolynomial right);
		friend const trigonometricPolynomial operator-(const trigonometricPolynomial left, const trigonometricPolynomial right);
		void addTerm(trigonometricMonom newTerm);
		std::complex<float> calculate(float t, float x);

	protected:
		std::vector<trigonometricMonom> terms;
	private:
};

#endif // TRIGONOMETRICPOLYNOMIAL_H
