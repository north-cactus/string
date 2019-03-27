#include <iostream>
#include <fstream>
#include <vector>
#include <boost/program_options.hpp>
#include "scalar2DFunction.h"
#include "EulerString.h"
#include "phase.h"
#include "trigonometricMonom.h"

namespace po = boost::program_options;

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
		//int m;
		//std::cout << "Quantity of mode of oscillation: ";
		//std::cin >> m;
		
		float a, b, imcoef, recoef;
		std::cin >> recoef >> imcoef >> a >> b;
		complex<float> coef(recoef, imcoef);
		trigonometricMonom tmp(coef, phase(a, b)), minus, plus;
		tmp.print();
		std::cout << std::endl << "0.2 *tmp = ";
		minus = 0.2 * tmp;
		(minus).print();
		std::cout << std::endl << "tmp * 5 = ";
		plus = tmp * 5;
		(plus).print();
		std::cout << std::endl << "tmp^2 = ";
		tmp = plus * minus;
		tmp.print();
		std::cout << '\n';
		
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
