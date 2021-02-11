#pragma once
#include "Node.h"
template<typename T>
class Iterator
{
public:
	//Iterator that points to a node
	Iterator<T>() { current = nullptr; };
	//Iterator that points to a specific node
	Iterator(Node<T>* node) { current = node; };
	//This iterates positively through the list of nodes by setting its own next to its current
	Iterator<T> operator ++();
	//This iterates negatively through the list of nodes by setting its own previous to its current
	Iterator<T> operator --();
	//this test to see if the data contained in the node this iterator is pointing to is equal
	const bool operator ==(const Iterator<T>& iter);
	//this tests to see if the data contained in the node this iterator is pointing to is not equal
	const bool operator !=(const Iterator<T>& iter);

	T operator *();
	//Pointer to the current Node
	Node<T>* current;
};

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return Iterator<T>(current->next);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return Iterator<T>(current->previous);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//checks to see if the data specifically stored is equal
	if (current->data == iter.current->data)
		return true;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	//checks to see if the data specifically stored is unequal
	if(current->data != iter.current->data)
		return true;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return T();
}
