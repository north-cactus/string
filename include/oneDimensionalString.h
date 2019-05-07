#ifndef ONEDIMENSIONALSTRING_H
#define ONEDIMENSIONALSTRING_H

#include "trigonometricPolynomial.h"
#include <string>

class oneDimensionalString : public trigonometricPolynomial
{
	public:
		int playToWav (std::string outputFileName, float soundRecieiverCoordinate, float time_s);
		oneDimensionalString();
		~oneDimensionalString();

	protected:

	private:
};

#endif // ONEDIMENSIONALSTRING_H
