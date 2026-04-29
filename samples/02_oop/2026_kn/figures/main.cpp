#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>

#include "figures.hpp"
#include "figure.hpp"
#include "group.hpp"
#include "circle.hpp"
#include "fplot.hpp"
#include "halfplane.hpp"
#include "square.hpp"
#include "triangle.hpp"


Group createGroup()
{
	Group maindoc,
	      g,
		  inner;

	Circle c1({{7,7},2,"Ivan"}), 
	       c2({{4,4},1,"Boyana"}), 
		   c3({{2, 2}, 1, "John"}),
		   c4({{0, 0}, 1, "Mary"});

	Square s1 ({{2,2},1,"Ivan"}), 
	       s2({{4,4},1,"Stefan"}), 
		   s3({{0, 0}, 2, "Ivan"}),
		   s4({{2, 1}, 2, "Mariya"});
	
	g.addFigure(&c1);
	g.addFigure(&s1);

	inner.addFigure(&s2);
	inner.addFigure(&c2);

	g.addFigure(&inner);

	maindoc.addFigure(&c3);
	maindoc.addFigure(&c4);
	maindoc.addFigure(&g);
	maindoc.addFigure(&s3);
	maindoc.addFigure(&s4);

	return maindoc;
	
}


int main() {

	Group doc = createGroup();

	{
		std::ofstream out("image.ppm");
		doc.drawToPPM(out);
	}

	std::ofstream file ("figures.fig");
	doc.serialize(file);

	file.close();

	std::ifstream in("figures.fig");

	std::string dummy;
	in >> dummy;

	Group d;
	d.deserialize(in);
	d.serialize(std::cout);


}
