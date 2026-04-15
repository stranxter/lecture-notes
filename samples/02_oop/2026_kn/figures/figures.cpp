#include "figures.hpp"
#include <cfloat>
#include <iostream>
#include <cmath>

Figure::Figure() : center(0, 0) {
	std::cout << "Figure::Figure()\n";
	label = "No label";
}

Figure::Figure(const Point &_center, const char *_label) : label(_label), center(_center) {
	std::cout << "Figure::Figure(const Point &, const char *)\n";
}

Figure::Figure(const char *_label) : label(_label), center(0, 0) { std::cout << "Figure::Figure(const char*)\n"; }

Square::Square(const Point &pos, double size, const char *_label) : Figure(pos, _label), size(size) {
	std::cout << "Square::Square()\n";
}

double Square::side() const { return size; }

double Square::area() const {
	std::cout << "Square::area()\n";
	return side() * side();
}

double Square::perimeter() const { return 4 * side(); }

bool Square::containsCentered(const Point &p) const { return std::max(std::abs(p.x), std::abs(p.y)) < size / 2; }

Circle::Circle(const Point &center, double _r, const char *_label) : Figure(center, _label), r(_r) {
	std::cout << "Circle::Circle()\n";
}

double Circle::area() const {
	std::cout << "Circle::area()\n";
	return 3.14 * r * r;
}

double Circle::perimeter() const { return 2 * 3.14 * r; }

bool Circle::containsCentered(const Point &p) const {
	double distSq = p.x * p.x + p.y * p.y;
	return distSq <= r * r;
}

double sumArea(Figure *figs[], unsigned size) {
	double result = 0;
	for (unsigned int i = 0; i < size; ++i) {
		result += figs[i]->area();
	}

	return result;
}

FunctionPlot::FunctionPlot(const Point &_center, std::function<double(double)> _f, double width, const char *_label)
	: Figure(_center, _label), f{_f}, width(width) {}

double FunctionPlot::area() const { return 0; }
double FunctionPlot::perimeter() const { return FLT_MAX; }
bool   FunctionPlot::containsCentered(const Point &p) const { return std::abs(p.y - f(p.x)) < width; }

HalfPlane::HalfPlane(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
HalfPlane::HalfPlane(const Point &A, const Point &B)
	: a(A.y - B.y),
	  b(B.x - A.x),
	  c(A.x * B.y - B.x * A.y)	   //
{}

double HalfPlane::area() const { return FLT_MAX; }
double HalfPlane::perimeter() const { return FLT_MAX; }
bool   HalfPlane::containsCentered(const Point &p) const { return p.x * a + p.y * b + c >= 0; }

Triangle::Triangle(const Point &_A, const Point &_B, const Point &_C)
	: A(_A), B(_B), C(_C), a(_B, _C), b(_C, _A), c(_A, _B) {}

double square(double x) { return x * x; }

double Triangle::area() const {
	// TODO: this is ugly
	double a = std::sqrt(square(B.x - C.x) + square(B.y - C.y));
	double b = std::sqrt(square(C.x - A.x) + square(C.y - A.y));
	double c = std::sqrt(square(A.x - B.x) + square(A.y - B.y));
	double s = (a + b + c) / 2;
	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
double Triangle::perimeter() const {
	double a = std::sqrt(square(B.x - C.x) + square(B.y - C.y));
	double b = std::sqrt(square(C.x - A.x) + square(C.y - A.y));
	double c = std::sqrt(square(A.x - B.x) + square(A.y - B.y));
	return a + b + c;
}
bool Triangle::containsCentered(const Point &p) const {
	return a.containsCentered(p) && b.containsCentered(p) && c.containsCentered(p);
}

void graphToPPM(const std::vector<Figure *> &figures, std::ostream &out) {
	const unsigned int size	  = 500;	 // [0...size-1]
	const double	   bounds = 5;		 // [-bounds, +bounds]

	out << "P3\n" << size << " " << size << "\n" << 255 << "\n";

	for (unsigned int j = 0; j < size; ++j) {
		for (unsigned int i = 0; i < size; ++i) {
			Point currentPoint = {-bounds + i * bounds * 2 / size, -bounds + (size - j - 1) * bounds * 2 / size};
			bool  isInside	   = false;
			for (Figure *f : figures) {
				if (f->contains(currentPoint)) { isInside = true; }
			}
			if (isInside) out << "255 255 255 ";
			else out << "0 0 0 ";
			out << "\n";
		}
	}
}
