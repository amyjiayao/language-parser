#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cstring>
#include <cctype>
#include <sstream> 
using namespace std;

class Token{
public:
	char kind; // what kind of token
	double value; // for numers: a value
	Token(): kind('0'), value(0){}
	Token(char k): kind(k), value(0){}
	Token(char k, double v): kind(k), value(v){}
};

ostream& operator<< (ostream& out, const Token t);

class Parser {
private:
  /* declare constants */
  
  /* declare member variables;
   may include a string postfix queue and a integer operator stack */
	LinkedQueue<Token> postfix; // postfix quene
	LinkedStack<Token> opStack; // operator stack
	vector<Token> tokens; // array of tokens

  /* declare utility functions */
  int precedence(char c);
  
public:
	vector<Token> stringtoken(string s);
  // constructor
	Parser(string s): opStack(), postfix() { 
		tokens = stringtoken(s);
	}  
  
  // accessor method
	LinkedQueue<Token> getPostfix() { return postfix; }
  
  // operations
	void printInfix();
	void printPostfix();
	void to_postfix();
};

#endif
