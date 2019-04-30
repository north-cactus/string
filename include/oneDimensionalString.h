#ifndef ONEDIMENSIONALSTRING_H
#define ONEDIMENSIONALSTRING_H

#include "trigonometricPolynomial.h"
#include <string>

class oneDimensionalString : public trigonometricPolynomial
{
	public:
		void playToWav (std::string outputFileName, float time_s);

	protected:

	private:
};

#endif // ONEDIMENSIONALSTRING_H
