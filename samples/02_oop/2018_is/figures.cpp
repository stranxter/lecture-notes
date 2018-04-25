#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class Figure {
  public:
  Figure () {countAllTypesOfFigures++;}
  char label [15];
  virtual double surface () = 0;
  virtual int getType () = 0;
  virtual void save (std::ostream&) = 0;
  virtual void read (std::istream&) = 0;

  static size_t getObjectsCount ()
  {
    return countAllTypesOfFigures;
  }

private:
  static size_t countAllTypesOfFigures;
};

size_t Figure::countAllTypesOfFigures = 0;

class Rectangle : public Figure {
public:
  Rectangle (double _a, double _b): a(_a), b(_b){}
  double surface ()
  {
    return a*b;
  }
  int getType ()
  {
    return 0;
  }
  void save (std::ostream &out)
  {
    out << "rectangle: " << a << " " << b << " ";
  }
  void read (std::istream &in)
  {
     in >> a >> b;
  }
private:
  double a,b;
};

class Square : public Figure {
public:
  Square (double _a): a(_a){}
  double surface ()
  {
    return a*a;
  }
  int getType ()
  {
    return 1;
  }
  void save (std::ostream &out)
  {
    out << "square: " << a << " ";
  }

  void read (std::istream &in)
  {
     in >> a;
  }

private:
  double a;
};

Figure* figureFactory (std::string type)
{
  if (type == "square:")
  {
    return new Square (0);
  } else if (type == "rectangle:")
  {
    return new Rectangle (0,0);
  } else {
    assert (false);
  }

  return nullptr;
}

double sumSurfaces (Figure *figures[],size_t n)
{
  double sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    sum += figures[i]->surface();
  }
  return sum;
}

std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures)
{
  out << figures.size () << " ";

  for (size_t i = 0; i < figures.size(); i++)
  {
    figures[i]->save (out);
  }
  return out;
}

std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures)
{

  size_t n;
  in >> n;

  for (size_t i = 0; i < n; i++)
  {
    //трябва да можем да определим типа на новия обект
    std::string type;
    in >> type;
    Figure *newFigure = figureFactory(type);
    newFigure->read (in);
    figures.push_back (newFigure);
  }
  return in;
}


/*
std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures)
{
  for (size_t i = 0; i < figures.size(); i++)
  {
    switch (figures[i]->getType())
    {
      case 0:
             //Rectangle
             out << "Rectange: "
                 << ((Rectangle*)figures[i])->a
                 << " "
                 << ((Rectangle*)figures[i])->b
                 << " ";
             break;
      case 1:
             //Square
             out  << "Square: "
                  << ((Square*)figures[i])->a
                  << " ";

             break;
    }
  }
  return out;
}
*/

int main ()
{

  Rectangle r (2,3);
  Square c (10);

  Figure *f = &r;
  std::cout << f->surface () << std::endl;

  f = &c;
  std::cout << f->surface ()<< std::endl;;

  Figure *figures[] = {new Square (2),
                       new Rectangle (2,3),
                       new Square (4),
                       new Square (5)};

  std::cout << sumSurfaces (figures, 4);

  std::ofstream file ("test.txt");

  std::vector<Figure*> vfigures = {new Square (2),
                                   new Rectangle (2,3),
                                   new Square (4),
                                   new Square (5)};

  file << vfigures;
  file.close();

  std::vector<Figure*> vfigures2;
  std::ifstream inputfile ("test.txt");

  inputfile >> vfigures2;

  std::cout << "====================\n";

  std::cout << vfigures << std::endl;
  std::cout << vfigures2 << std::endl;

  std::cout << "count = " << Figure::getObjectsCount() << std::endl;



}
