#include "Parser.h"

using namespace std;

/* initialize constants here */
ostream& operator<< (ostream& out, const Token t){
	if(t.kind=='8'){
		out << t.value;
	}
	else{
		out << t.kind;
	}
	return out;
}

//initialize constants, delimiters and precedence table 
int Parser::precedence(char c){
	int p = -1;
	if(c=='('){
		p = 0;
	}
	else if(c=='+'||c=='-'){
		p = 1;
	}
	else if (c=='*'||c=='/'){
		p = 2;
	}
	else if (c=='^'){
		p = 3;
	}
	else{
		p = -1;
	}
	return p;
}

vector<Token> Parser::stringtoken(string s){
	vector<Token> t;
	int x = 0; // counter
	istringstream ss(s);
	char c = ss.get();
	while(c !='#'){ // if is not end
		if(isdigit(c)){
			ss.unget();
			ss >> x;
			Token t1;
			t1.value = x;
			t1.kind = '8';
			t.push_back(t1);
			c = ss.get();
		}
		else{
			Token t2{c};
			t.push_back(t2);
			c = ss.get();
		}
	}
	return t;
}

/* describe rest of functions */
void Parser::printPostfix(){ 
	cout << postfix << endl;
}

void Parser::printInfix(){
	for(int i=0; i<tokens.size();i++){
		cout << tokens[i];
	}
	cout << endl;
}

void Parser::to_postfix(){ 
	for (int i=0; i<tokens.size();i++){
		if(isalpha(tokens[i].kind)||tokens[i].kind=='8'){
			// if tokens is letters or numerical values
			postfix.enqueue(tokens[i]);
		}
		else{
			switch(tokens[i].kind){
				case '(':
					opStack.push(tokens[i]); 
					break;
				case ')':
					while (opStack.top().kind != '(') { 
						postfix.enqueue(opStack.top()); 
						opStack.pop();
					}
					opStack.pop(); //remove left parenthesis
					break;
				case '#':
					while (!opStack.isEmpty() ) { 
						postfix.enqueue(opStack.top()); 
						opStack.pop();
					} 
					break;
				case '^': case '/': case '*':
				case '+': case '-':
					while (!opStack.isEmpty()&&
					precedence(opStack.top().kind)>=precedence(tokens[i].kind)) { 
						postfix.enqueue(opStack.top()); 
						opStack.pop();
					} 
					opStack.push(tokens[i]); 
					break;
				default:
					cerr << "Invalid Token: " << tokens[i] << endl; 
					break;
			}
		}
		
	}
	// check if opStack is empty
	while(!opStack.isEmpty()){
		postfix.enqueue(opStack.top());
		opStack.pop();
	}
}