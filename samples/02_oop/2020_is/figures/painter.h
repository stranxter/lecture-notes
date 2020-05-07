#include "visitor.h"

class Painter: public Visitor
{
    public:

    Painter();

    void processCircle(Circle*);
    void processRectangle(Rectangle*);
    void processGroup(Group*);

    private:
    double offset_x, offset_y;

};