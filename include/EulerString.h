#ifndef EULERSTRING_H
#define EULERSTRING_H

#include "scalar2DFunction.h"


class EulerString : public scalar2DFunction
{
	public:
		EulerString();
		virtual ~EulerString();
		void simpleNextMoment(float c);
	protected:

	private:
};

#endif // EULERSTRING_H
