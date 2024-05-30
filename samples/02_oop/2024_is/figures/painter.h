#pragma once

#include "util.h"
#include "visitor.h"

class Painter: public Visitor
{
    public:
    Painter(const Point& _origin);
    void visitCircle(Circle* c) override;
    void visitTriangle(Triangle* t) override;
    void visitSquare(Square* s) override;
    void visitGroup(Group* g) override;

    private:
    Point origin;
};

