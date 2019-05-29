#ifndef __FUNCTION_H
#define __FUNCTION_H

class Function
{
    public:
    virtual double value (double x) = 0;
    virtual Function* clone () = 0;

    virtual ~Function();

};

#endif