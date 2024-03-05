#pragma once

#include "visitor.h"

class Painter : public Visitor
{
    public:
    Painter();

    void visitCircle(Circle*);
    void visitRect(Rect*);
    void visitGroup(Group*);

    private:
    Point2D offset;
};