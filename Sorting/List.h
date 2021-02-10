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
	Node<T> m_head = NULL;
	//The node at the end of the list
	Node<T> m_tail = NULL;
	//The quantity of Nodes in the list
	int m_nodeCount = 0;
};

template<typename T>
inline void List<T>::destroy()
{	
	//loop through length of Nodes
	for (int i = 0; i <= m_nodeCount; i++)
	{
		//Uses the begin iterator to iterate to the next node, and then delete the node previous to it
		begin()++;
		~begin().current->previous;
	}		
}

template<typename T>
inline const void List<T>::print()
{
	//Create a new iterator pointing to the first node, which begin already does
	Iterator<T> iterate = new Iterator<T>(begin());
	//Loops through the list of nodes for the length of how many nodes there are
	for (int i = 0; i < m_nodeCount; i++)
	{
		//prints the data at the current node in the list
		std::cout << iterate.current->data;
		//points the iterator at the next node to be looped
		++iterate;
	}
	//once done, need to delete the iterator
	~iterate;
	return void();
}

template<typename T>
inline void List<T>::initialize()
{
	//Create an empty null node for convienience
	Node<T> nullNode = new Node<T>();
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
	if (m_nodeCount == 0 || (m_head == nullptr && m_tail == nullptr))
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
	//for each item in the list
	//see if the next item is larger
    //if it is, swap
	//should loop until no changes are made
	Iterator<T> compare = new Iterator<T>(begin());
	Iterator<T> to = new Iterator<T>(++begin());
	bool somethingSwapped = true;
	while (somethingSwapped)
	{
		for (int i = 0; i < m_nodeCount; i++)
		{
			for (int j = m_nodeCount; j < i + 1; i--)
			{

			};
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
	for (int i = 0; i < other.m_nodeCount; i++)
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
	//This Iterator just points to the head of the list
	return Iterator<T>();
}

template<typename T>
inline const Iterator<T> List<T>::end()
{
	//This Iterator just points to the end of the list
	return Iterator<T>();
}

template<typename T>
inline const bool List<T>::contains(const T object)
{
	//New Iterator to iterate through our list
	Iterator<T> iterate = new Iterator<T>(begin());
	//Loop for potentially the entire length of the list
	for (int i = 0; i < m_nodeCount; i++)
	{
		//check to see if the current node being pointed at has data matching what we're looking for
		if (iterate.current->data == object)
			return true;
		//Have the iterator point to the next node
		++iterate;
	}
	//if the function has made it this far, no object was found in the list
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//need to insert a new node of type T value
	Node<T> newNode = new Node<T>(value);
	//set the new nodes next node to be the current first node
	newNode.next = m_head;
	//set the old first node's previous equal to the new first node
	m_head.previous = newNode;
	//Move the begin iterator back to the first node
	--begin();
	//Count the node that has been added
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//need to insert a new node of type T value
	Node<T> newNode = new Node<T>(value);
	//This new node will go after the tail so this becomes the tails next
	newNode = m_tail.next;
	//We also have to set this nodes previous equal to the old tail
	newNode.previous = m_tail;
	//We now update the tail pointer so its pointing to this new node
	++end();
	//Count the node that has been added
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Fail This Function if index is out of range
	if(index > m_nodeCount || index < 0)
		return false;
	//Create a new iterator to find the index requested
	Iterator<T> seek = new Iterator<T>(begin());
	//Place the iterator so that it points to the index requested
	for (int i = 0; i < index; i++)
		++seek;
	//Create a new Node to go in said index
	Node<T> newData = new Node<T>(value);
	//Set this new Node to see the old Node that is now infront
	newData.next = seek.current;
	//Set the old node to see this new data behind it
	seek.current->previous = newData;
	//Delete the iterator it is no longer needed
	~seek;
	//Count the node that has been added
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Fail This Function if index is out of range
	if (index > m_nodeCount || index < 0)
		return false;
	//Create a new iterator to find the value requested
	Iterator<T> seek = new Iterator<T>(begin());
	//Find the value
	for (int i = 0; i < m_nodeCount; i++)
	{
		//Test each nodes data to see if equal
		if (seek.current->data != value)
		{
			//If not, increment to the next one
			++seek;
		}			
		else //if it is, set the node previous and the node next to connect and delete the node
		{
			//set the previous node's next to be the next node
			seek.current->previous->next = seek.current->next;
			//set the next node's previous to be the previous node
			seek.current->next->previous = seek.current->previous;
			//Delete the node that seek is pointing to as it is no longer necessary
			~*seek;
		}
	}
	//Delete the iterator as it is no longer necessary
	~seek;
	//Count the node that has been removed
	m_nodeCount--;
}
