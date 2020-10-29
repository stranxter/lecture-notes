#ifndef __EXPRESSION_H
#define __EXPRESSION_H

int apply (char op, int left, int right);
int priority (char c);
bool isOperator (char c);

#endif
