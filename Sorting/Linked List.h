#pragma once
template<typename T>
class Node
{
public:
	Node<T>();
	Node<T>(T value);
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
class Iterator
{
public:
	Iterator<T>();
	Iterator(Node<T>* node);
	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();
private:
	Node<T>* current;
};

template<typename T>
class List
{
public:
	List() { initialize(); }
	List(const List<T>& other) { copyList(other); };
	~List() { destroy(); };
	const List<T>& operator = (const List<T>& otherList);
	Iterator<T> begin();
	Iterator<T> end();
	const bool contains(const T object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void destroy();
	void print() const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	void sort();
private:
	Node<T> m_head;
	Node<T> m_tail;
	int m_nodeCount;
};

template<typename T>
inline Node<T>::Node()
{
	data = nullptr;
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator()
{
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return Iterator<T>();
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return false;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return false;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return T();
}

template<typename T>
inline List<T>::List()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline Iterator<T> List<T>::begin()
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::end()
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
	m_head = value;
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

template<typename T>
inline void List<T>::print() const
{
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return 0;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}