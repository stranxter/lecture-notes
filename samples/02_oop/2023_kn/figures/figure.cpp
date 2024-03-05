#include "figure.h"
#include <vector>

Figure::Figure():col({0,0,0})
{
    
}

std::ostream& operator << (std::ostream &out, const std::vector<Figure*>& figures)
{
    out << figures.size() << std::endl;
    for (Figure *f : figures)
    {
        f->writeToStream(out);
        out << std::endl;
    }
    return out;
}

void Figure::setColor(sdlw::color _c)
{
    col = _c;
}

sdlw::color Figure::getColor()
{
    return col;
}
