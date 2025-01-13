#pragma once

/*! \class DoubleLinkedListNode
	\brief A node on the double linked list data structure using templates and smart pointers
	\file doubleLinkedListNode.h
	\var data
	\var prev
	\var next
	\fn getData()
	\fn getPrev()
	\fn getNext()
*/

// Includes for use in class and templates
#include <string>
#include <memory>

// using namespace std
using namespace std;

//! Using a class template DoubleLinkedListNode
template <class G>
class DoubleLinkedListNode
{
private:
	G data; //!< The element held in the node
	shared_ptr<DoubleLinkedListNode> prev; //!< Previpus element in the list
	shared_ptr<DoubleLinkedListNode<G>> next; //!< Next element in the list
public:
	DoubleLinkedListNode(G newData, shared_ptr<DoubleLinkedListNode<G>> newPrev, shared_ptr<DoubleLinkedListNode<G>> newNext); //!< Default constructor
	G getData(); //!< Get the data from the node
	shared_ptr<DoubleLinkedListNode<G>> getPrev(); //!< Get the previous node
	shared_ptr<DoubleLinkedListNode<G>> getNext(); //!< Get the next node
};

template <class G>
DoubleLinkedListNode<G>::DoubleLinkedListNode(G newData, shared_ptr<DoubleLinkedListNode<G>> newPrev, shared_ptr<DoubleLinkedListNode<G>> newNext) //!< Default constructor
{
	data = newData; // Sets data to newData value
	prev = newPrev; // Sets prev to newPrev value
	next = newNext; // Sets next to newNext value
}

template <class G>
G DoubleLinkedListNode<G>::getData() //!< Get the data from the node
{
	return data; // Returns data value
}

template <class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getPrev() //!< Get the previous node
{
	return prev; // Returns prev value
}

template <class G>
shared_ptr<DoubleLinkedListNode<G>> DoubleLinkedListNode<G>::getNext() //!< Get the next node
{
	return next; // Returns next value
}