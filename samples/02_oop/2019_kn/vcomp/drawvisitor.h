#ifndef _DRAWVISITOR__H
#define _DRAWVISITOR__H

#include "visitor.h"

class DrawingVisitor : public Visitor
{
    public:

    DrawingVisitor ();

    void visitReactangle (Rect*);
    void visitCircle (Circle*);
    void visitGroup (Group*);

    private:
    int offsetx, offsety;

};

#endif