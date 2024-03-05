#pragma once

#include "visitor.h"
#include <iostream>

class Serializer : public Visitor
{

    Serializer(std::ostream &_out);

    void visitCircle(Circle*);
    void visitRect(Rect*);
    void visitGroup(Group*);

    private:
    std::ostream& out;
};