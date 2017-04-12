#include <assert.h>
#include "figure.h"

#include "circle.h"
#include "square.h"


Figure* Figure::factory (std::string type)
{
  if (type == "circle")
    return new Circle (0,0,0);
  if (type == "square")
    return new Square (0,0,0,0);

  assert (false);
  return nullptr;
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
