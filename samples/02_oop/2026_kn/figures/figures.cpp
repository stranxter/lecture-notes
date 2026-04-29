#include "figures.hpp"
#include "group.hpp"
#include "circle.hpp"
#include "figure.hpp"
#include "fplot.hpp"
#include "halfplane.hpp"
#include "square.hpp"
#include "triangle.hpp"



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

std::ostream& operator << (std::ostream& out, const Point& p)
{
	return out << p.x << " " << p.y;
}

std::istream& operator >> (std::istream& in, Point& p)
{
	return in >> p.x >> p.y;
}

void Square::serialize(std::ostream& out) const
{
	out << "[Sq] "
		<< label << "\n"
	    << center << " "
		<< size << " ";
}

void Square::deserialize(std::istream& in)
{
	std::getline(in, label);
	in >> center >> size;
}

double Square::side() const { return size; }

double Square::area() const {
	std::cout << "Square::area()\n";
	return side() * side();
}

Figure* Square::copy() const
{
	return new Square(*this);
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

void Circle::serialize(std::ostream& out) const
{
	out << "[Cir] "
		<< label << "\n"
	    << center << " "
		<< r << " ";
}

void Circle::deserialize(std::istream& in)
{
	std::getline(in, label);
	in >> center >> r;
}


bool Circle::containsCentered(const Point &p) const {
	double distSq = p.x * p.x + p.y * p.y;
	return distSq <= r * r;
}

Figure* Circle::copy() const
{
	return new Circle(*this);
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

void FunctionPlot::serialize(std::ostream& out) const
{
	throw "Unable to serialize function.";
}

void FunctionPlot::deserialize(std::istream& in)
{
	throw "Unable to deserialize function.";
}

Figure* FunctionPlot::copy() const
{
	return new FunctionPlot(*this);
}

HalfPlane::HalfPlane(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
HalfPlane::HalfPlane(const Point &A, const Point &B)
	: a(A.y - B.y),
	  b(B.x - A.x),
	  c(A.x * B.y - B.x * A.y)	   //
{}


void HalfPlane::serialize(std::ostream& out) const
{
	out << "[Hpl] "
	    << label << "\n"
	    << a << " " << b << " " << c;
}

void HalfPlane::deserialize(std::istream& in)
{
	std::getline(in, label);
	in >> a >> b >> c;
}

double HalfPlane::area() const { return FLT_MAX; }
double HalfPlane::perimeter() const { return FLT_MAX; }
bool   HalfPlane::containsCentered(const Point &p) const { return p.x * a + p.y * b + c >= 0; }

Figure* HalfPlane::copy() const
{
	return new HalfPlane(*this);
}

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

Figure* Triangle::copy() const
{
	return new Triangle(*this);
}

void Triangle::serialize(std::ostream& out) const
{
	out << "[Tri] "
	    << label << "\n"
	    << A << " " << B << " " << C;
}

void Triangle::deserialize(std::istream& in)
{
	std::getline(in, label);
	in >> A >> B >> C;
}


bool Triangle::containsCentered(const Point &p) const {
	return a.containsCentered(p) && b.containsCentered(p) && c.containsCentered(p);
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
	} else if (figure == "[Grp]")
	{
		return new Group;
	} else 
	{
		std::cerr << "Unrecognized figure type: " << figure << std::endl;
		throw "Unrecognized figure type.";
	}
	return nullptr;
}
