// LinkedStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
    
template<typename T>
class LinkedStack
{
private:
  /* declare member variables here */
  DoublyLinkedList<T> ll;
  
public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };
   
   /* declare rest of functions */
   LinkedStack(): ll() {} // default constructor
   bool isEmpty() const {return ll.isEmpty();}
   void push(const T elem); // insert first
   T pop() throw(StackEmptyException); // remove first
   T top() const throw(StackEmptyException); // return first
   friend std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
};

/* describe rest of the functions here */
template<typename T>
void LinkedStack<T>::push(const T elem) {
	ll.insertFirst(elem); // insert first
} 

template<typename T>
T LinkedStack<T>::pop() throw(StackEmptyException){
	if (ll.isEmpty()){
		throw StackEmptyException();
	}
	return ll.removeFirst(); // remove first
}
 
template<typename T>
T LinkedStack<T>::top() const throw(StackEmptyException){
	if (ll.isEmpty()){
		throw StackEmptyException();
	}
	return ll.first(); // return first
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
  /* fill in the function */  
   out << stack.ll;
   return out;
}

#endif
