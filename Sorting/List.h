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
	Node<T>* m_head = nullptr;
	//The node at the end of the list
	Node<T>* m_tail = nullptr;
	//The quantity of Nodes in the list
	int m_nodeCount = 0;
};

template<typename T>
inline void List<T>::destroy()
{	
	if (begin().current == nullptr)
		return void();
	Iterator<T>* pointer = new Iterator<T>(begin().current->next);
	//loop through length of Nodes
	for (int i = 0; i <= m_nodeCount - 2; i++)
	{
		//Uses the begin iterator to iterate to the next node, and then delete the node previous to it		
		delete pointer->current->previous;
		pointer->current = pointer->current->next;
	}	
	m_head = pointer->current;
	m_tail = pointer->current;
	this->m_nodeCount = 0;
}

template<typename T>
inline const void List<T>::print()
{
	if (m_nodeCount == 0)
		return void();
	//Create a new iterator pointing to the first node, which begin already does
	Iterator<T>* iterate = new Iterator<T>(begin());
	//Loops through the list of nodes for the length of how many nodes there are
	for (int i = 0; i < m_nodeCount; i++)
	{
		//prints the data at the current node in the list		
		std::cout << iterate->current->data;
		
		//points the iterator at the next node to be looped
		iterate->current = iterate->current->next;
	}
	std::cout << " " << std::endl;
	//once done, need to delete the iterator
	return void();
}

template<typename T>
inline void List<T>::initialize()
{
	//Create an empty null node for convienience
	Node<T>* nullNode = new Node<T>();
	//this new null node is both the head and tail of the list
	m_head = nullNode;
	m_tail = nullNode;
	//this node is null and not counted
	m_nodeCount = 0;
}

template<typename T>
inline const bool List<T>::isEmpty()
{
	//Checks for obvious signs of an empty list
	if (m_nodeCount == 0 || (m_head == NULL && m_tail == NULL))
		return true;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	//checks to see if index is in range before we look
	if (index > m_nodeCount)
		return false;
	//until we get to the index requested, set the iterator's next to be its current as to increment
	for (int i = 0; i < index; i++)
		++iter;
	//once the iterator is on the desired node, return the data stored inside said node
	return iter.current->data;
}

template<typename T>
inline void List<T>::sort()
{
	if (m_nodeCount < 2)
		return void();
	//Create a pointer to point to the tail in the list
	Iterator<T>* iteratorJ = new Iterator<T>(end());
	//swapping for sorting is set to true to allow entry into the while loop
	bool somethingSwapped = true;
	//while something gets swapped in the loop, repeat the loop
	while (somethingSwapped)
	{
		//as of right now nothing has been swapped
		somethingSwapped = false;
		//for each item in the list
		for (int i = 0; i < getLength(); i++)
		{
			//set the iterator to point to the tail
			iteratorJ->current = end().current;
			//this loop loops until the iterator faces the second node in the list
			for (int j = getLength() - i; j > i; j--)
				if (iteratorJ->current->previous != nullptr) //tests to see if the iterator is pointing at the head which has already been compared
					if (iteratorJ->current->data < iteratorJ->current->previous->data) //sees if the data is smaller than the data before
					{
						//if the node after the iterators next node pointer is not null
						if (iteratorJ->current->next->next != nullptr && iteratorJ->current->next != nullptr)
							iteratorJ->current->next->previous = iteratorJ->current->previous; //set the next nodes previous to be the iterators previous
						else
							m_tail = iteratorJ->current->previous;
						//if the previous nodes previous is not nullptr
						if (iteratorJ->current->previous->previous != nullptr)
							iteratorJ->current->previous->previous->next = iteratorJ->current; //then we set the previous node's previous node's next to be the current
						else
							m_head = iteratorJ->current; //if the previous nodes previous is nullptr then this new item is the new head
						//set the next nodes previous to be the iterators previous
						iteratorJ->current->next->previous = iteratorJ->current->previous;
						//fights against head nodes previous being bull
						if(iteratorJ->current->previous->previous != nullptr)
							iteratorJ->current->previous->previous->next = iteratorJ->current; //set the node to be swapped's previous nodes next to be this iterator
						//set the node to be swapped next to be this iterators next
						iteratorJ->current->previous->next = iteratorJ->current->next;
						//set this iterators next node to be the node to be swapped
						iteratorJ->current->next = iteratorJ->current->previous;
						//set the iterators previous to be the node to be swapped previous
						iteratorJ->current->previous = iteratorJ->current->previous->previous;
						//set the node to be swapped previous to be this iterator
						iteratorJ->current->next->previous = iteratorJ->current;
						//if we got here then a swap was made
						somethingSwapped = true;
					}
					else //if we got here then the swap was not made and we need to check the next two nodes
						iteratorJ->current = iteratorJ->current->previous;
		}
	}
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	//Create a new iterator to loop through the list starting with the first node
	Iterator<T> copy = new Iterator<T>(begin());
	//while we have not iterated through the length of the list that we are copying
	for (int i = 0; i < other.m_nodeCount; i++)
	{
		//create a new node with the same data as the node in the same index of the other list
		Node<T> newData = new Node<T>(copy.current);
		//place the new node in our new list
		pushFront(newData);
	}
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	//Create a new iterator to loop through the list starting with the first node
	Iterator<T> copy = new Iterator<T>(begin());
	//while we have not iterated through the length of the list that we are copying
	for (int i = 0; i < otherList.m_nodeCount; i++)
	{
		//create a new node with the same data as the node in the same index of the other list
		Node<T> newData = new Node<T>(copy.current);
		//place the new node in our new list
		pushFront(newData);
		m_nodeCount++;
	}
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_head);
}

template<typename T>
inline const Iterator<T> List<T>::end()
{
	return Iterator<T>(m_tail);
}

template<typename T>
inline const bool List<T>::contains(const T object)
{
	//New Iterator to iterate through our list
	Iterator<T>* iterate = new Iterator<T>(begin());
	//Loop for potentially the entire length of the list
	for (int i = 0; i < m_nodeCount; i++)
	{
		//check to see if the current node being pointed at has data matching what we're looking for
		if (iterate->current->data == object)
			return true;
		//Have the iterator point to the next node
		iterate->current = iterate->current->next;
	}
	//if the function has made it this far, no object was found in the list
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//need to insert a new node of type T value
	Node<T>* newNode = new Node<T>(value);
	if (this->m_head == nullptr)
		m_head = newNode;
	//place the new node behind the head node
	m_head->previous = newNode;
	//place the head node in front of the new node
	newNode->next = m_head;
	//set the head node to this node
	m_head = newNode;
	if (m_nodeCount == 0)
		m_tail = newNode;
	//increment number of nodes
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Create a new node of data to be put into the list
	Node<T>* newNode = new Node<T>(value);
	//check to see if this is the first node to be put into the list
	if (m_nodeCount == 0)
	{
		//assign the new node to be before the null node
		m_tail->previous = newNode;
		//set the new nodes next to be the null node
		newNode->next = m_tail;
		//set the new tail to be the new node
		m_tail = newNode;
		m_head = newNode;
		//increment number of nodes
		m_nodeCount++;
		//leave this function
		return;
	}
	//if its not the first thing in the list, place node after tail
	m_tail->next = newNode;
	//set new nodes previous to be the old tail
	newNode->previous = m_tail;
	//set the old tail to be the new node
	m_tail = newNode;
	//increment number of nodes
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Fail This Function if index is out of range
	if(index >= m_nodeCount || index < 0)
		return false;
	//Create a new iterator to find the index requested
	Iterator<T>* seek = new Iterator<T>(begin());
	//Place the iterator so that it points to the index requested
	for (int i = 0; i < index; i++)
		seek->current = seek->current->next;
	//Create a new Node to go in said index
	Node<T>* newData = new Node<T>(value);
	//set the new data's next to be the node at this index
	newData->next = seek->current;
	//set the new data's previous to be the old nodes previous
	newData->previous = seek->current->previous;
	//set this nodes previous nodes next node to be the new data
	seek->current->previous->next = newData;
	//set the old datas previous to be the new data
	seek->current->previous = newData;
	//Delete the iterator it is no longer needed
	delete seek;
	//Count the node that has been added
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Fail This Function if the list is empty
	if (isEmpty() == true)
		return false;
	//Create a new iterator to find the value requested
	Iterator<T>* seek = new Iterator<T>(begin());
	//Find the value
	for (int i = 0; i < m_nodeCount; i++)
	{
		//Test each nodes data to see if equal
		if (seek->current->data != value)
		{
			//If not, increment to the next one
			seek->current = seek->current->next;
		}			
		else //if it is, set the node previous and the node next to connect and delete the node
		{
			//set the previous nodes next to be this nodes next
			if (seek->current->previous != nullptr)
				seek->current->previous->next = seek->current->next;
			else
				m_head = seek->current->next;
			//set the next nodes previous to be this nodes previous
			if(seek->current->next != nullptr)
				seek->current->next->previous = seek->current->previous;
		}
	}
	//Delete the node that seek is pointing to as it is no longer necessary
	delete seek;
	//Count the node that has been removed
	m_nodeCount--;
}
