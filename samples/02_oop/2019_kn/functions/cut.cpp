#include "cut.h"

Cut::Cut (Function *_originalFunction)
{
    originalFunction = _originalFunction->clone();
}

Cut::Cut(const Cut &original)
{
    originalFunction = original.originalFunction->clone();
}

Cut::~Cut ()
{
    delete originalFunction;
}

double Cut::value (double x)
{
    double y = originalFunction->value (x);

    if (y >= 0)
    {
        return y;
    }
    return 0;
}

Function* Cut::clone()
{
    return new Cut (*this);
}
