#pragma once

#include "figure.hpp"
#include <vector>

class Group : public Figure
{

    public:

    Group(const Group& original);
    Group();

	virtual double area() const override;
	virtual double perimeter() const override;
	virtual void serialize(std::ostream&) const override;
	virtual void deserialize(std::istream&) override;

    void addFigure(Figure *);

	//bool contains(const Point &p) const { return this->containsCentered({p.x - center.x, p.y - center.y}); }

    virtual bool containsCentered(const Point &p) const override;

    void drawToPPM(std::ostream &out);

    Figure* copy() const override;

    ~Group();

    private:
    std::vector<Figure*> contents;

};