#include <iostream>
#include <fstream>
#include <vector>
#include <boost/program_options.hpp>
#include "scalar2DFunction.h"
#include "EulerString.h"
#include "phase.h"

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
		int m;
		std::cout << "Quantity of mode of oscillation: ";
		std::cin >> m;
		vector<phase> phases;
		for (int i = 0; i < m; i++)
		{
			float a, b;
			std::cin >> a >> b;
			phase tmp(a, b);
			phases.push_back(tmp);
		}
		float t, x;
		std::cout << "t: ";
		std::cin >> t;
		std::cout << "x: ";
		std::cin >> x;
		
		std::cout << "phases[0].calculate(t, x) = " << phases[0].calculate(t, x) << '\n';

		if (phases.size() >= 2) 
		{
			phase tmp = phases[0] - phases[1];
			std::cout << "(phases[0] - phases[1]).calculate(t, x) = " << tmp.calculate(t, x) << '\n';
		}
		float coef;
		std::cin >> coef;
		phase tmp = phases[0] * coef;
		std::cout << "phases[0]*coef.calculate(t, x) = " << tmp.calculate(t, x) << '\n';
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
