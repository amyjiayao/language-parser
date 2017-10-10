//replace with your implemented version

#ifndef TEMPLATED_DOUBLY_LINKED_LIST_H
#define TEMPLATED_DOUBLY_LINKED_LIST_H

//programming assignment 3

#include <cstdlib>
#include <stdexcept>
#include <iostream>


using namespace std;

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

template<typename T> class DoublyLinkedList; // class declaration

// list node
template<typename T>
class DListNode {
private:
  T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode<T>(T e=T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {}
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template<typename T>
class DoublyLinkedList {
protected:
  DListNode<T> header, trailer; // O(1)
public:
  DoublyLinkedList() : // constructor 
    header(T()), trailer(T()) // O(1)
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor // O(n)
  ~DoublyLinkedList(); // destructor // O(n)
  // assignment operator // O(n)
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); 
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } // O(1)
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; } // O(1)
  // check if the list is empty
  bool isEmpty() const { return header.next == &trailer; } // O(1)
  T first() const; // return the first object // O(1)
  T last() const; // return the last object // O(1)
  void insertFirst(T newobj); // insert to the first of the list // O(1)
  T removeFirst(); // remove the first node // O(1)
  void insertLast(T newobj); // insert to the last of the list // O(1)
  T removeLast(); // remove the last node // O(1)
};
// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll); // O(n)

// copy constructor
// O(n)
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  // Copy from dll
  // Complete this function
	DListNode<T> *ptr = dll.getFirst();
	if(ptr != NULL){ // Test if d11 is empty
		DListNode<T> *newNode = new DListNode<T>();
		this->insertLast(ptr->getElem());
		ptr = ptr->next;
		while(ptr != &dll.trailer){
			this->insertLast(ptr->getElem());
			ptr = ptr->next;
		}
	}
	else{
		cout << "Error: Empty Input!" << endl;
	}
}

// assignment operator
// O(n)
template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
	if (this == &dll) {return *this;} // Test if it is assignning to self
	this-> ~DoublyLinkedList<T>(); // Delete self
	// Complete this function
	DListNode<T> *ptr = dll.getFirst();
	if(ptr != NULL){ // Test if d11 is empty
		DListNode<T> *newNode = new DListNode<T>();
		this->insertLast(ptr->getElem());
		ptr = ptr->next;
		while(ptr != &dll.trailer){
			this->insertLast(ptr->getElem());
			ptr = ptr->next;
		}
	}
	else{
		cout << "Error: Empty Input!" << endl;
	}
	return *this;
}

// insert the object to the first of the linked list
// O(1)
template<typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  // Complete this function
  header.next->prev = newNode;
  header.next = newNode;
}

// insert the object to the last of the linked list
// O(1)
template<typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list
// O(1)
template<typename T>
T DoublyLinkedList<T>::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  // Complete this function
  DListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}

// remove the last object of the list
// O(1)
template<typename T>
T DoublyLinkedList<T>::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

// destructor
// O(1)
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList<T>()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
// O(1)
template<typename T>
T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  // Complete this function
  return header.next->obj;
}

// return the last object
// O(1)
template<typename T>
T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  
  return trailer.prev->obj;
}

// output operator
// O(n)
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
  // Complete this function
	DListNode<T> *ptr = dll.getFirst();
	// While loop to print out ptr
	while(ptr != dll.getAfterLast()){
		out << ptr->getElem();
		ptr=ptr->getNext();
	}
	return out;
};


#endif
