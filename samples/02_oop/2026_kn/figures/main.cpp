#include <iostream>
#include <fstream>

#include "figures.hpp"

int main() {
	std::vector<Figure *> c = {new Circle{{2, 2}, 1, "Circle 2"},	  //
							   new Circle{{0, 0}, 1, "Circle 1"},	  //
							   new Square{{0, 0}, 2, "Square 1"},	  //
							   new Square{{2, 1}, 2, "Square 2"},	  //
							   new FunctionPlot({-2, 0}, [](double x) -> double { return x * x; }, 0.1, "x*x")};

	std::cout << sumArea(c.data(), 4) << std::endl;

	std::cout << c[0]->contains({1, 1}) << std::endl;
	std::cout << c[0]->contains({0.5, 0.5}) << std::endl;

	std::cout << c[2]->contains({0.5, 0.5}) << std::endl;
	std::cout << c[2]->contains({2, 2}) << std::endl;

	std::cout << c[4]->contains({2, 4}) << std::endl;
	std::cout << c[4]->contains({3, 10}) << std::endl;

	{
		std::ofstream out("image.ppm");
		graphToPPM(c, out);
	}
}
