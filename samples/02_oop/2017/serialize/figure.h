#ifndef __FIGURE_H
#define __FIGURE_H

#include <iostream>
#include <string>
#include <vector>

class Figure;

struct NameAndPointerPair
{
  std::string figureType;
  Figure* hollowFigure;

  NameAndPointerPair (std::string ft, Figure* hf):figureType(ft),hollowFigure(hf){}

};

class Figure
{
public:
  virtual double surface () = 0;

  virtual void save (std::ostream &out) = 0;

  virtual void load (std::istream &in) = 0;

  virtual Figure* spawn () = 0;

  static Figure* factory (std::string);

private:

  static std::vector<NameAndPointerPair> allFigureTypes;

protected:

  static void addFigureType (std::string,Figure*);
};

std::ostream& operator << (std::ostream &, std::vector<Figure*>);
std::istream& operator >> (std::istream &, std::vector<Figure*>&);



#endif
