#include "figure.h"
#include <vector>

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