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
	//loop through length of Nodes
	for (int i = 1; i <= m_nodeCount; i++)
	{
		//Uses the begin iterator to iterate to the next node, and then delete the node previous to it		
		delete begin().current->previous;
	}		
}

template<typename T>
inline const void List<T>::print()
{
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
	//Create an iterator to point to the first node
	Iterator<T>* compare = new Iterator<T>(begin());
	//Create an iterator to point to the second node
	Iterator<T>* to = new Iterator<T>(begin().current->next);
	//have a modifyable bool to tell us when the list has been sorted
	bool somethingSwapped = true;
	//Until the list is sorted
	while (somethingSwapped)
	{
		//Compare the first node to the rest of the nodes
		for (int i = 0; i < m_nodeCount; i++)
		{
			//until something is swapped, this function should exit when 
			somethingSwapped = false;
			//starting with the last node until we are at the first nodes next
			for (int j = m_nodeCount; j < i + 1; i--)
			{
				//compare to see if the first node is bigger than the node being compared
				if (compare->current->data > to->current->data)
				{
					//Change the first nodes next to be the comparison nodes next
					compare->current->next = to->current->next;
					//Change the comparison node's previous to be the first nodes previous;
					to->current->previous = compare->current->previous;
					//Change the first nodes previous to be the comparison node
					compare->current->previous = to->current;
					//Change the comparisons nodes next to be the first node
					to->current->next = compare->current;
					//Since we made a change we have to specify or else the loop wont function
					somethingSwapped = true;
				}
				//after the nodes are compared, set the to iterator to be the previous of the current
				--to;
				//if nothing changed during that loop, then the list is in order
				somethingSwapped = false;
				return;
			};
			//once looped through the entire list of nodes, start comparing the second node to the rest of the nodes
			++compare;
		};
	};
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
	//place the new node behind the head node
	m_head->previous = newNode;
	//place the head node in front of the new node
	newNode->next = m_head;
	//set the head node to this node
	m_head = newNode;
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
			seek->current->previous->next = seek->current->next;
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
