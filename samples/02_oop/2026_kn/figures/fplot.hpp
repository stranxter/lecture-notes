#pragma once
#include "figure.hpp"
#include <functional>

class FunctionPlot : public Figure {
	std::function<double(double)> f;
	double						  width;

   public:
	FunctionPlot(const Point &center, std::function<double(double)> f, double width, const char *_label);

	void serialize(std::ostream& out) const override;
	virtual void deserialize(std::istream&) override;

	double area() const override;
	double perimeter() const override;
	bool   containsCentered(const Point &) const override;

	Figure* copy() const override;

};


