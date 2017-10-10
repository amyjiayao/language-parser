#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"

class Evaluator {
private:
  // user-defined exceptions
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };     
public:
  /* declare member variables; 
    may include a string postfix queue and a double value stack */
	LinkedQueue<Token> postfix;
	LinkedStack<Token> stack;
	
  /* declare utility functions */
	void replaceValue();
	double getValue(); // returns the result of expression evaluation

	Evaluator(Parser &par): postfix(par.getPostfix()) {} // constructor
  
};

#endif
