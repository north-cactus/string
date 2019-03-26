#ifndef PHASE_H
#define PHASE_H


class phase
{
	public:
		phase();
		phase(float init_omeg, float init_k);
		virtual ~phase();
		float calculate(float t, float x);
	
		friend const phase operator+(const phase left, const phase right);
		friend const phase operator-(const phase left, const phase right);
		friend const phase operator*(const phase ph, const float coef);
		friend const phase operator*(const float coef, const phase ph);
	protected:
	
	private:
		float omega;
		float k;
};

#endif // PHASE_H
