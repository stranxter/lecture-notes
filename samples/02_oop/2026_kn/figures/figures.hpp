#pragma once

#include <functional>
#include <string>

struct Point {
	double x, y;
};

class Figure {
   public:
	Figure();
	Figure(const Point &center, const char *_label);
	Figure(const char *_label);

	virtual double area() const		 = 0;
	virtual double perimeter() const = 0;

	bool contains(const Point &p) const { return this->containsCentered({p.x - center.x, p.y - center.y}); }

   protected:
	virtual bool containsCentered(const Point &p) const = 0;
	std::string	 label;
	Point		 center;
};

class Square : public Figure {
   public:
	double size;

	Square(const Point &pos, double size, const char *_label);

	double area() const override;
	double perimeter() const override;
	double side() const;
	bool   containsCentered(const Point &) const override;
};

class Circle : public Figure {
   public:
	double r;

	Circle(const Point &point, double _r, const char *_label);

	double area() const override;
	double perimeter() const override;

	bool containsCentered(const Point &) const override;
};

class FunctionPlot : public Figure {
	std::function<double(double)> f;
	double						  width;

   public:
	FunctionPlot(const Point &center, std::function<double(double)> f, double width, const char *_label);

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;
};

double sumArea(Figure *figs[], unsigned size);

class HalfPlane : public Figure {
	double a, b, c;

   public:
	HalfPlane(double a, double b, double c);
	HalfPlane(const Point &a, const Point &b);

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;
};

class Triangle : public Figure {
	Point	  A, B, C;
	HalfPlane a, b, c;

	Triangle(const Point &_A, const Point &_B, const Point &_C);

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;
};


void graphToPPM(const std::vector<Figure *> &cofigures, std::ostream &out);

