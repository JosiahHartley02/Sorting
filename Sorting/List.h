#pragma once
#include <iostream>
#include "Iterator.h"
template<typename T>
class List
{
public:
	//Base list with a single nullptr Node
	List() { initialize(); };
	//List initializer for creating a copy of an existing list
	const List(const List<T>& other);
	//Deletes the nodes in the list
	~List() { destroy(); };
	//Sets the nodes in this list to be equal to nodes in OtherList
	const List<T>& operator = (const List<T>& otherList);
	//Iterator that only points to the beginning node
	const Iterator<T> begin();
	//Iterator that only points to the end node
	const Iterator<T> end();
	//Checks to see if T oject is in the list
	const bool contains(const T object);
	//Places a new node at the start of the list, replacing the begin iterators current pointer
	void pushFront(const T& value);
	//Places a new node at the end of the list, replacing the end iterators current pointer
	void pushBack(const T& value);
	//Places a new node at this specific index, becoming the current Node's previous
	bool insert(const T& value, int index);
	//Finds a specific node and removes the node, setting the previous Nodes next pointer to the next node
	bool remove(const T& value);
	//Deletes all nodes in the list
	void destroy();
	//Prints all nodes in the list
	const void print();
	//Initializes the list for use
	void initialize();
	//checks to see if the list contains any nodes
	const bool isEmpty();
	//returns the data stored within the node that the iterator is pointing to
	bool getData(Iterator<T>& iter, int index);
	//Returns the number of nodes in the list
	const int getLength() { return m_nodeCount; };
	//Uses bubble sort to compare sizes of data within nodes to organize least to greatest
	void sort();
private:
	//The node at the start of the list
	Node<T> m_head;
	//The node at the end of the list
	Node<T> m_tail;
	//The quantity of Nodes in the list
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	Node<T> nullNode = new Node<T>()
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline void List<T>::destroy()
{	
	//loop through length of Nodes
	for (int i = 0; i < m_nodeCount; i++)
		~begin().current->previous+i;  //delete what the iterator is pointing at, it is pointing at the 2nd node's previous, which is the 1st node.
}

template<typename T>
inline const void List<T>::print()
{
	std::cout << 
	return void();
}

template<typename T>
inline void List<T>::initialize()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline const bool List<T>::isEmpty()
{
	if (m_nodeCount == 0 || (m_head == nullptr && m_tail == nullptr))
		return true;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index > m_nodeCount)
		return false;
	for (int i = 0; i < index; i++)
		iter++;
	return iter.current->data;
}
template<typename T>
inline void List<T>::sort()
{
	//Iterator<T> sort = new Iterator();	
	//for(int i = 0; i < m_nodeCount; i++)
	//	for(int j = m_nodeCount; j < i + 1; i--)
	//		if (getData(sort, j) < getData(sort, i))
	//		{
	//			Node<T> tempNode = sort.current;
	//		}
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{
	return Iterator<T>();
}

template<typename T>
inline const Iterator<T> List<T>::end()
{
	return Iterator<T>();
}

template<typename T>
inline const bool List<T>::contains(const T object)
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//need to insert a new node of type T value
	Node<T> newNode = new Node<T>(value);
	//set the new nodes next node to be the current first node
	newNode.next = begin().current;
	//set the old first node's previous equal to the new first node
	begin().current->previous = newNode;
	//Move the begin iterator back to the first node
	begin()--;

}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}
