#pragma once

/*! \class DoubleLinkedList
    \brief A double linked list data structure with templates and smart pointers
	\file doubleLinkedList.h
*/

// Includes for class templates and node header file
#include <string>
#include <memory>
#include "doubleLinkedListNode.h"

// using namespace std
using namespace std;

//! Using a class template DoubleLinkedList
template <class G>
class DoubleLinkedList
{
private :
	unsigned int size; //!< Number of elements in the list
	shared_ptr<DoubleLinkedListNode<G>> head; //!< First element in the list
	shared_ptr<DoubleLinkedListNode<G>> current; //!< Current element in the list
	shared_ptr<DoubleLinkedListNode<G>> beforeCurrent; //!< Element before the current element
	shared_ptr<DoubleLinkedListNode<G>> afterCurrent; //!< Element after the current element
	shared_ptr<DoubleLinkedListNode<G>> tail; //!< Last element in the list
	shared_ptr<DoubleLinkedListNode<G>> front; //!< Front of the list
	shared_ptr<DoubleLinkedListNode<G>> back; //!< Back of the list
	shared_ptr<DoubleLinkedListNode<G>> tempFront; //!< Temporary front while new first element is added
	shared_ptr<DoubleLinkedListNode<G>> tempBack; //!< Temporary back while new last element is added
	shared_ptr<DoubleLinkedListNode<G>> tempCurrent; //!< Temporary current element while new element is added
	shared_ptr<DoubleLinkedListNode<G>> tempPrev; //!< Temporary previous node while new node is added to list
	shared_ptr<DoubleLinkedListNode<G>> tempNext; //!< Temporary next node while new node is added to list
public :
	DoubleLinkedList(); //!< Default constructor
	void addFront(G newElement); //!< Add to front of the list
	void addBack(G newElement); //!< Add to back of the list
	void addBeforeCurrent(G newElement); //!< Add before the current element of the list
	void addAfterCurrent(G newElement); //!< Add after the current element of the list
	void removeHead(); //!< Remove first element
	void removeTail(); //!< Remove last element
	void sort(); //!< Sort the list
	G getHead(); //!< Returns first node
	G getTail(); //!< Returns last node
	G getCurrent(); //!< Returns current node
	G traverseBack(); //!< Traverses list from back to front
	G traverseFront(); //!< Traverses list from front to back
	unsigned int getSize(); //!< Returns list size
	bool empty(); //!< Returns whether or not list is empty
};

template <class G>
DoubleLinkedList<G>::DoubleLinkedList() //!< Default constructor
{
	head = nullptr; // head points to NULL
	current = nullptr; // current points to NULL
	tail = nullptr; // tail points to NULL
	front = current; // front points to current
	back = current; // back points to current
	tempFront = front; // tempFront points to front
	tempBack = back; // tempBack points to back
	tempCurrent = current; // tempCurrent points to current
	size = 0; // Size is 0 to begin with
}

template <class G>
void DoubleLinkedList<G>::addFront(G newElement) //!< Add to front of the list
{
	tempNext = head; // tempNext points to head
	head = shared_ptr<DoubleLinkedListNode<G>>(new DoubleLinkedListNode<G>(newElement, nullptr, tempNext)); // Insert a new node at the front of the list
	front = head; // front is head node
	current = head; // current is head node
	size++; // size incremented by 1
	if (size == 1) // If size is 1
		tail = head; // tail node is the same as head node
}

template <class G>
void DoubleLinkedList<G>::addBack(G newElement) //!< Add to back of the list
{
	tempPrev = tail; // tempPrev points to tail
	tail = shared_ptr<DoubleLinkedListNode<G>>(new DoubleLinkedListNode<G>(newElement, tempPrev, nullptr)); // Insert a new npde at the back of the list
	back = tail; // back is tail node
	current = tail; // current is tail node
	size++; // size incremented by 1
	if (size == 1) // If size is 1
		head = tail; // head node is the same as tail node
}

template <class G>
void DoubleLinkedList<G>::addBeforeCurrent(G newElement) //!< Add before the current element of the list
{
	if (current == head) // If current node is head node
		addFront(newElement); // Pass newElement to addFront function
	else // If current node is not head node
		beforeCurrent = shared_ptr<DoubleLinkedListNode<G>>(new DoubleLinkedListNode<G>(newElement, current->getPrev(), current)); // Insert a new node before the current node
	size++; // size incremented by 1
}

template <class G>
void DoubleLinkedList<G>::addAfterCurrent(G newElement) //!< Add after the current element of the list
{
	if (current == tail) // If current node is tail node
		addBack(newElement); // Pass newElement to addBack function
	else // If current node is not tail node
		afterCurrent = shared_ptr<DoubleLinkedListNode<G>>(new DoubleLinkedListNode<G>(newElement, current, current->getNext())); // Insert a new node after the current node
	size++; // size incremented by 1
}

template <class G>
void DoubleLinkedList<G>::removeHead() //!< Remove first element
{
	head = head->getNext(); //!< head points to next node in list
	current = head; //!< New current node is head
	size--; //!< size decremented by 1
}

template <class G>
void DoubleLinkedList<G>::removeTail() //!< Remove last element
{
	tail = tail->getPrev(); //!< tail points to second-to-last node in list
	current = tail; //!< New current node is tail
	size--; // size decremented by 1
}

template <class G>
void DoubleLinkedList<G>::sort() //!< Sort the list
{

}

template <class G>
G DoubleLinkedList<G>::getHead() //!< Returns first node
{
	string result = head->getData(); // result variable contains data from head node
	return result; // Returns result
}

template <class G>
G DoubleLinkedList<G>::getTail() //!< Returns last node
{
	string result = tail->getData(); // result variable contains data from tail node
	return result; // Returns result
}

template <class G>
G DoubleLinkedList<G>::getCurrent() //!< Returns current node
{
	string result = current->getData(); // result variable contains data from node current node
	return result; // Returns result
}

template <class G>
G DoubleLinkedList<G>::traverseBack() //!< Traverses list from back to front
{
	string result = tail->getData(); // result variable contains data from tail node
	tail = tail->getPrev(); // Replaces tail node data with the data from previous node
	size--; // size decremented by 1
	return result; // Returns result
}

template <class G>
G DoubleLinkedList<G>::traverseFront() //!< Traverses list from front to back
{
	string result = head->getData(); // result variable contains data from head node
	head = head->getNext(); // Replaces head node data with the data from next node
	size--; // size decremented by 1
	return result; // Returns result
}

template <class G>
unsigned int DoubleLinkedList<G>::getSize() //!< Returns list size
{
	return size; // Returns size
}

template <class G>
bool DoubleLinkedList<G>::empty() //!< Returns whether or not list is empty
{
	return size == 0; // Returns true if size is 0
}