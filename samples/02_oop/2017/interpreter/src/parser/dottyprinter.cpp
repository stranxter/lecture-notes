#include <iostream>
#include "dottyprinter.h"

int DottyPrinter::lastDottyId = 0;

DottyPrinter::DottyPrinter (std::ostream &out):output(out){}

void DottyPrinter::visit (ConstExpr *ce)
{
  dottyIdRoot = ++lastDottyId;

  output << dottyIdRoot
         << "[label=\""
         << ce->getDoubleVal()
         << "\"];\n";
}
void DottyPrinter::visit (BinExpr *be)
{
  dottyIdRoot = ++lastDottyId;

  //печатане на оператора
  output << dottyIdRoot
         << "[label=\""
         << be->getOperator()
         << "\"];\n";

  //отпечатване на подизразиате
  DottyPrinter leftPrinter (output), rightPrinter(output);

  be->getLeft()->accept (&leftPrinter);
  be->getRight()->accept (&rightPrinter);

  //отпечатване на дъгите

  output << dottyIdRoot
         << "->"
         << leftPrinter.dottyIdRoot << "\n";

  output << dottyIdRoot
         << "->"
        << rightPrinter.dottyIdRoot << "\n";


}
void DottyPrinter::visit (IfExpr *ie)
{
  dottyIdRoot = ++lastDottyId;

  //печатане на оператора
  output << dottyIdRoot
         << "[label=\"IF\"];\n";

  //отпечатване на подизразиате
  DottyPrinter condPrinter (output),
               thenPrinter (output),
               elsePrinter (output);

  ie->getCondition()->accept (&condPrinter);
  ie->getThenExpr()->accept (&thenPrinter);
  ie->getElseExpr()->accept (&elsePrinter);

  //отпечатване на дъгите

  output << dottyIdRoot
         << "->"
         << condPrinter.dottyIdRoot << "\n";
  output << dottyIdRoot
         << "->"
         << thenPrinter.dottyIdRoot << "\n";
 output << dottyIdRoot
        << "->"
        << elsePrinter.dottyIdRoot << "\n";


}

void DottyPrinter::print (Expression *expr)
{
  output << "digraph G{\n";
  expr->accept (this);
  output << "}\n";


}
