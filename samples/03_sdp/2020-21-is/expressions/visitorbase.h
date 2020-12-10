#ifndef __VISITORB__
#define __VISITORB__

#include "exptree.h"
#include <iostream>

class ExprVisitor
{
    public:
    virtual void processConstExpression(ConstExpression*) = 0;
    virtual void processOperatorExpression(OperatorExpression*) = 0;
};

class ExprDotExport : public ExprVisitor
{  
    public:
    ExprDotExport (std::ostream&);

    void processConstExpression(ConstExpression*);
    void processOperatorExpression(OperatorExpression*);

    private:
    std::ostream &out;

};

class EpxrEvaluator : public ExprVisitor
{  
    public:
    
    void processConstExpression(ConstExpression*);
    void processOperatorExpression(OperatorExpression*);

    int getResult();

    private:
    int result;

};



#endif