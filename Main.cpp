
#include <iostream>
#include <string>
#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"

using namespace std;

int main() {
  /* implement user menu */
  while(true){
		cout << "Enter an infix expression ending with # (type 'quit' to exit): ";
		string str;
		while(str.size() == 0)
			getline(cin,str);

		if (str == "quit") break; 
		
		// check if string end with #
		int flag  = 0;
		if(str[str.size()-1]!='#') flag++;
		
		// check if input is valid
		for(int i=0;i<str.size();i++){
			if ( (islower(str[i])!=0)|| isdigit(str[i]) 
				|| isspace(str[i]) || str[i]== '\0'
				|| str[i]== '(' || str[i]== ')'
				|| str[i]== '+'|| str[i]== '-'
				|| str[i]== '*'|| str[i]== '/'
				|| str[i]== '^' || str[i] == '#')
				flag = flag + 0;
			else flag++;
		}
		
		// check for parenthesis balance
		LinkedStack<char> paren;
		for(int i=0;i<str.size();i++){
			if (str[i]=='('){
				paren.push('1');
			}
			if (str[i]==')'){
				if (paren.isEmpty()){
					flag++;
				}
				else{
					paren.pop();
				}
			}
		}
		if(!paren.isEmpty()){
			flag++;
		}
		
		// proceed only with valid input
		if(flag!=0 || str.size()<=1){
			cout << "Invalid Input!" << endl;
		}
		else{
			Parser par(str); // new parser 
			cout << "Infix expression: "; par.printInfix(); 
			par.to_postfix(); // convert to postfix form 
			cout << "Postfix expression: "; par.printPostfix(); // print
			Evaluator eval(par);
			eval.replaceValue();
			cout << "Value of expression: " << eval.getValue() << endl;
		}
		//break;
  }
  return 0;  
}
