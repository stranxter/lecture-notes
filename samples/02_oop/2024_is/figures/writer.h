#include "visitor.h"


class Writer: public Visitor
{
    public:
    Writer(std::ostream& _out);
    void visitCircle(Circle* c) override;
    void visitTriangle(Triangle* t) override;
    void visitSquare(Square* s) override;
    void visitGroup(Group* g) override;

    private:
    std::ostream& out;
};