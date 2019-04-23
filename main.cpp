#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <boost/program_options.hpp>
#include "scalar2DFunction.h"
#include "EulerString.h"
#include "phase.h"
#include "trigonometricMonom.h"
#include "trigonometricPolynomial.h"

std::vector<std::complex<float>> fourierTransform(std::vector<std::complex<float>> &);

namespace po = boost::program_options;

const float pi = 3.1415926;

int main(int argc, char* argv[])
{
	po::options_description desc("Short description of options");
	desc.add_options()
	("help,h", "Show this help")
	("out,o", po::value<std::string>(), "Output file option. It requires one argument.")
	("analytical-solution,a", "Amplitudes of natural frequencies will be calculated by initial state of string.\n Result will be calculated with analytical solution.")
	;
	po::variables_map vm;
	try
	{
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
	}
	catch(po::error& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Use -h or --help for more information about options.\n";
		return 1;
	}
	if (vm.count("help"))
	{
		std::cout << desc << std::endl;
		return 1;
	}
	if (vm.count("out"))
	{
		std::cout << "Sorry, file output have not realized.\n";
		return 1;
	}
	if (vm.count("analytical-solution"))
	{
		int m; 
		float length, tmax, lstep, tstep, soundVelocity;
		std::cout << "length, tmax, lstep, tstep, soundVelocity: ";
		std::cin >> length >> tmax >> lstep >> tstep >> soundVelocity;
		std::cout << "Quantity of mode of oscillation: ";
		std::cin >> m;

		float fundamOmega = pi * soundVelocity / length;
		float fundamK = pi / length;

		trigonometricPolynomial P;

		std::vector<float> stringInitalCoordinates, cosCoef, sinCoef;

		for (int i = 0; i < m; i++)
		{
			float tmp;
			std::cin >> tmp;
			stringInitalCoordinates.push_back(tmp);
		}
		//Fourier transform
		for (int i = 0; i < m; i++)
		{
			cosCoef.push_back(0);
			sinCoef.push_back(0);
			for (int j = 0; j < m; j++)
			{
				cosCoef.back() += stringInitalCoordinates[j] * cos ( fundamK * i * length * j / ((float) m));
				sinCoef.back() += stringInitalCoordinates[j] * sin ( fundamK * i * length * j / ((float) m));
			}
			//std::cerr << cosCoef[i] << '\t' << sinCoef[i] << '\n';
		}
		for (int i = 1; i <= m; i++)
		{
			P.addTerm(trigonometricMonom(std::complex<float>(-cosCoef[i] / 2, sinCoef[i] / 2), phase(fundamOmega * i, fundamK * i)));
			P.addTerm(trigonometricMonom(std::complex<float>(cosCoef[i] / 2, sinCoef[i] / 2), phase(-fundamOmega * i, fundamK * i)));
		}
		for (float t = 0; t < tmax; t += tstep)
		{
			for (float l = 0; l < length; l += lstep) 
			{
				cout << l << '\t' << P.calculate(t, l).real() << '\t' << P.calculate(t, l).imag() << '\n';
			}
			cout << "\n\n";
		}
		return 0;
	}
	int n, m;
	float c;
	EulerString func;
	std::cout << "Maxes: ";
	func.readMaxes();
	std::cout << "coefficient C (sound velocity):";
	std::cin >> c;
	int quantityOfSteps, outCoef;
	std::cout << "quantity of steps: ";
	std::cin >> quantityOfSteps;
	std::cout << "out coef: ";
	std::cin >> outCoef;
	std::cout << "size of table (n, m): ";
	std::cin >> n >> m;
	func.readTable(n, m);
	std::cout 	<< "outCoef = " << outCoef << '\n'
			<< "quantity of steps = " << quantityOfSteps << '\n'
			<< "c = " << c << std::endl;
	for (int i = 0; i < quantityOfSteps; i++)
	{
		func.NextMoment(c);
		if (i % outCoef == 0)
		{
			func.printLastString();
			cout << '\n';
		}
	}
	return 0;
}

/*int main()
{
	int n;
	std::cin >> n;
	vector<complex<float>> in, out;
	for (int i = 0; i < n; i++)
	{
		float tmp;
		std::cin >> tmp;
		in.push_back(complex<float>(tmp, 0));
	}
	out = fourierTransform(in);
	for (int i = 0; i < out.size(); i++)
	{
		cout << i << '\t' << abs(out[i]) << '\t' << arg(out[i]) << '\n';
	}
	return 0;
}*/
std::vector<std::complex<float>> fourierTransform(std::vector<std::complex<float>> &in)
{
	std::vector<std::complex<float>> out;
	complex<float> powerCoef(0, -2 * pi / in.size());
	for (int j = 0; j < in.size(); j++)
	{
		out.push_back(std::complex<float>(0,0));
		for (int n = 0; n < in.size(); n++)
		{
			out.back() += in[n] * exp(powerCoef * complex<float>((j * n), 0));
		}
		out.back() /= in.size();
	}
	return out;
}
