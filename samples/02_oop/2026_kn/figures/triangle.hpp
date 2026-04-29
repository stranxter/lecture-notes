#pragma once
#include "figure.hpp"
#include "halfplane.hpp"

class Triangle : public Figure {
	Point	  A, B, C;
	HalfPlane a, b, c;

	public:
	Triangle(const Point &_A, const Point &_B, const Point &_C);
	void serialize(std::ostream& out) const override;
	virtual void deserialize(std::istream&) override;

	Figure* copy() const override;

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;
};
