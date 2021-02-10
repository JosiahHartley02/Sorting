#pragma once
template<typename T>
//Node Thought of Like A Train Cart
class Node
{
public:
	//Constructor that only holds position
	Node<T>();
	//Constructor that holds data
	Node<T>(T value);
	//points to the next node
	Node<T>* next;
	//points to the previous node
	Node<T>* previous;
	//the data that is being stored in type T
	T data;
};
//This Node contains no data, only how to get to the two adjacent nodes
template<typename T>
inline Node<T>::Node()
{
	//since this node only holds position, it stores no data
	data = nullptr;
	//the next node pointer is set to nullptr for initialization
	next = nullptr;
	//the previous node pointer is set to nullptr for initialization
	previous = nullptr;
}
//This node stores data of type T, and how to get to the nodes adjacent
template<typename T>
inline Node<T>::Node(T value)
{
	//data has been given for this node to store so it is stored
	data = value;
	//the next node pointer is set to nullptr for initialization
	next = nullptr;
	//the previous node pointer is set to nullptr for initialization
	previous = nullptr;
}
