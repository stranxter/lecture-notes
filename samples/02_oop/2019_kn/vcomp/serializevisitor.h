#ifndef _SERIALIZEVISITOR__H
#define _SERIALIZEVISITOR__H

#include "visitor.h"
#include <iostream>

class SerializeVisitor : public Visitor
{
    public:

    SerializeVisitor (std::ostream&);

    void visitReactangle (Rect*);
    void visitCircle (Circle*);
    void visitGroup (Group*);

    private:
    std::ostream& out;
    
    unsigned int depth;
};

#endif