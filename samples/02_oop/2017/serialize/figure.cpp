#include <assert.h>
#include <string>
#include "figure.h"

#include "circle.h"
#include "square.h"


Figure* Figure::factory (std::string type)
{

for (int i = 0; i < allFigureTypes.size(); i++)
{
  if (allFigureTypes[i].figureType == type)
     return allFigureTypes[i].hollowFigure->spawn();
}

assert (false);
return nullptr;

/*  if (type == "circle")
    return new Circle (0,0,0);
  if (type == "square")
    return new Square (0,0,0,0);
*/
}

std::ostream& operator << (std::ostream &out, std::vector<Figure*> figures)
{

  out << figures.size() << " ";

  for (int i = 0; i < figures.size(); i++)
  {
    figures[i]->save(out);
  }

  return out;
}
std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures)
{
  size_t size;
  in >> size;
  std::string type;

  for (size_t i = 0; i < size; i++)
  {
    in >> type;
    Figure *newFigure = Figure::factory (type);
    newFigure->load (in);
    figures.push_back (newFigure);
  }

  return in;
}

std::vector<NameAndPointerPair> Figure::allFigureTypes;


void Figure::addFigureType (std::string typeName,Figure *fig)
{
  allFigureTypes.push_back (NameAndPointerPair(typeName,fig));
}
