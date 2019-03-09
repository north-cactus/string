#include <iostream>
#include <fstream>
#include <vector>
#include <boost/program_options.hpp>
#include "scalarFunction.h"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description desc("Short description of options");
    desc.add_options()
    ("help,h", "Show this help")
    ("out,o", po::value<std::string>(), "Output file option. It requires one argument.")
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
        //std::cout << vm["out"].as<std::string>() << std::endl;
        std::cout << "Sorry, file output have not realized.\n";
        return 1;
    }
    int n, m;
    scalar2DFunction func;
    std::cout << "Maxes: ";
    func.readMaxes();
    std::cout << "size of table (n, m): ";
    std::cin >> n >> m;
    func.readTable(n, m);
    /*//differentiation
    std::cout << "d: ";
    int d;
    std::cin >> d;
    std::cout << "derivative: ";
    for (int i = 0; i < func.getTable().size(); i++)
    {
        std::cout << i << '\t' << func.getTable()[i][0] << '\t' << func.xderivative(i, 0, d) << '\n';
    }*/
    //func.printMaxes();
    //std::cout << endl;
    //func.printTable();
    /*int t;
    std::cout << "t = ";
    std::cin >> t;*/
    for (int i = 0; i < 100; i++)
    {
        func.simpleNextMoment(0.00001);
    }
    //func.printTable();
    func.getTableWithNumbers();
    return 0;
}
