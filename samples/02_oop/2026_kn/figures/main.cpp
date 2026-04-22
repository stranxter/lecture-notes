#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>

#include "figures.hpp"

std::ostream& operator <<(std::ostream &out, const std::vector<Figure*>& figures) 
{
	out << figures.size() << "\n";
	for (const Figure *fig : figures)
	{
		fig->serialize(out);
		out << "\n";
	}

	return out;
} 

Figure* figureFactory(const std::string& figure)
{
	if (figure == "[Cir]")
	{
		return new Circle({0,0},0,"dummy");
	} else if (figure == "[Sq]")
	{
		return new Square({0,0},0,"dummy");
	} else if (figure == "[Tri]")
	{
		return new Triangle({0,0},{0,0},{0,0});
	} else if (figure == "[HPl]")
	{
		return new HalfPlane(0,0,0);
	} else 
	{
		std::cerr << "Unrecognized figure type: " << figure << std::endl;
		throw "Unrecognized figure type.";
	}
	return nullptr;
}

std::istream& operator >>(std::istream &in, std::vector<Figure*>& figures) 
{

	std::string type;
	int count;
	in >> count;

	for(int i = 0; i < count; ++i)
	{
		in >> type;
		Figure *fig = figureFactory(type);
		fig->deserialize(in);
		figures.push_back(fig);
	}

	return in;
}


int main() {
	std::vector<Figure *> c = {new Circle{{2, 2}, 1, "John"},	  //
							   new Circle{{0, 0}, 1, "Mary"},	  //
							   new Square{{0, 0}, 2, "Ivan"},	  //
							   new Square{{2, 1}, 2, "Mariya"}};//,	  //
							   //new FunctionPlot({-2, 0}, [](double x) -> double { return x * x; }, 0.1, "x*x")};

							   
	std::cout << sumArea(c.data(), 4) << std::endl;

	std::cout << c[0]->contains({1, 1}) << std::endl;
	std::cout << c[0]->contains({0.5, 0.5}) << std::endl;

	std::cout << c[2]->contains({0.5, 0.5}) << std::endl;
	std::cout << c[2]->contains({2, 2}) << std::endl;

	//std::cout << c[4]->contains({2, 4}) << std::endl;
	//std::cout << c[4]->contains({3, 10}) << std::endl;

	{
		std::ofstream out("image.ppm");
		graphToPPM(c, out);
	}

	std::ofstream file ("figures.fig");
	file << c;

	file.close();

	std::ifstream in("figures.fig");
	std::vector<Figure*> d;
	in >> d;

	std::cout << d;


}
