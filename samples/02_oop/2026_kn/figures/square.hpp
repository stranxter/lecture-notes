#pragma once
#include "figure.hpp"

class Square : public Figure {
   public:
	double size;

	Square(const Point &pos, double size, const char *_label);

	void serialize(std::ostream& out) const override;
	virtual void deserialize(std::istream&) override;

	double area() const override;
	double perimeter() const override;
	double side() const;
	bool   containsCentered(const Point &) const override;

	Figure* copy() const override;
};
