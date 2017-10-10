#include "Evaluator.h"
#include <cmath>
#include <cctype>
#include <map>

using namespace std;

void Evaluator::replaceValue(){
	LinkedQueue<Token> newpost;
	char a;
	map<char, double> value;
	while (!postfix.isEmpty()) { 
		a = postfix.first().kind;
		if(isalpha(a)){ // replace letters with doubles
			if(value.find(a)==value.end()){
				double b;
				cout << "Please enter a numerical value to replace " << a << ": ";
				cin >> b;
				value[a]=b;
				Token t{'8',b}; // store 8 as type for double
				newpost.enqueue(t);
			}
			else{
				Token t2{'8',value[a]};
				newpost.enqueue(t2);
			}
			postfix.dequeue();
		}
		else{
			newpost.enqueue(postfix.dequeue());
		}
	}
	postfix = newpost;
}
	
double Evaluator::getValue() {
	LinkedStack<double> ls;
	double val;
	while(!postfix.isEmpty()){
		if(isdigit(postfix.first().kind)!=0){
			// push digital numbers to ls
			ls.push(postfix.first().value);
			postfix.dequeue();
		}
		else{ // return calculated results 
			double x=ls.pop();
			double y=ls.pop();
			char op=postfix.dequeue().kind;
			switch(op){
				case'+': ls.push(x+y); val = x+y; break;
				case'-': ls.push(y-x); val = y-x; break;
				case'*': ls.push(x*y); val = x*y; break;
				case'/': ls.push(y/x); val = y/x; break;
				case'^': ls.push(pow(y,x)); val = pow(y,x); break;
				
			}
		}
	}
	return val;
}  
