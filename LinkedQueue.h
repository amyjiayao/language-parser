// LinkedQueue.h

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> class LinkedQueue;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template<typename T>
class LinkedQueue {
private:
   /* declare member variables here */
   DoublyLinkedList<T> ll; // internal LinkedList object

public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

   /* declare rest of functions */
   LinkedQueue(): ll(){} // constructor
   ~LinkedQueue(){ll.~DoublyLinkedList();} // destructor
   bool isEmpty() const {return ll.isEmpty();}
   T first() const throw(QueueEmptyException); // return first
   void enqueue(T elem); // insert last
   T dequeue() throw(QueueEmptyException); // remove first
   friend std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue) {return out << queue.ll;};
};

/* describe rest of the functions here */
template<typename T>
T LinkedQueue<T>::first() const throw(QueueEmptyException){
	if (ll.isEmpty()){
		throw QueueEmptyException();
	}
	return ll.first(); // return first
} 

template<typename T>
void LinkedQueue<T>::enqueue(T elem){
	ll.insertLast(elem); // insert last
} 

template<typename T>
T LinkedQueue<T>::dequeue() throw(QueueEmptyException){
	if (ll.isEmpty()){
		throw QueueEmptyException();
	}
	return ll.removeFirst(); // remove first
} 

#endif
