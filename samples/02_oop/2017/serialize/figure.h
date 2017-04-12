#ifndef __FIGURE_H
#define __FIGURE_H

#include <iostream>
#include <string>
#include <vector>

class Figure
{
public:
  virtual double surface () = 0;

  virtual void save (std::ostream &out) = 0;

  static Figure* factory (std::string);
};

std::ostream& operator << (std::ostream &, std::vector<Figure*>);

#endif
