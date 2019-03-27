#ifndef TRIGONOMETRICMONOM_H
#define TRIGONOMETRICMONOM_H
#include <complex>
#include "phase.h"

class trigonometricMonom
{
	public:
		trigonometricMonom();
		trigonometricMonom(std::complex<float> coef, phase phs);
		virtual ~trigonometricMonom();
		std::complex<float> calculate(float t, float x);
		const trigonometricMonom operator+();
		const trigonometricMonom operator-();
		friend const trigonometricMonom operator*(const trigonometricMonom left, const trigonometricMonom right);
		friend const trigonometricMonom operator*(const trigonometricMonom left, const std::complex<float> right);
		friend const trigonometricMonom operator*(const std::complex<float> left, const trigonometricMonom right);
		friend const trigonometricMonom operator/(const trigonometricMonom left, const trigonometricMonom right);
		friend const trigonometricMonom operator/(const trigonometricMonom left, const std::complex<float> right);
		friend const trigonometricMonom operator/(const std::complex<float> left, const trigonometricMonom right);
		void print();

	protected:
		std::complex<float> coef;
		phase phs;
	private:
};

#endif // TRIGONOMETRICMONOM_H
