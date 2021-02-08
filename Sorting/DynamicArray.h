#pragma once
template<typename T>
class DynamicArray
{
public:
	DynamicArray<T>();
	~DynamicArray<T>();
	void addItem(T item);
	bool removeItem(T item);
	void sortItems();
	bool getItem(int index, T* item);
	int getLength();
	void print();
private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_length = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_items;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArr = new T[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
		tempArr[i] = m_items[i];

	tempArr[getLength()] = item;

	m_items = tempArr;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	bool itemRemoved = false;
	int itemsRemoved = 0;
	int j = 0;

	for (int i = 0; i < getLength(); i++)
		if (m_items[i] == item)
			itemsRemoved++;

	if (itemsRemoved == 0)
		return itemRemoved;

	T* tempArr = new T[getLength() - itemsRemoved];

	for(int i = 0; i < getLength(); i++)
		if (item != m_items[i])
		{
			tempArr[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	m_items = tempArr;
	m_length -= itemsRemoved;
	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (m_items[j] < m_items[j - 1])
			{
				T tempArr = m_items[j];
				m_items[j] = m_items[j - 1];
				m_items[j - 1] = tempArr;
			}
		}
	}
}

template<typename T>
inline bool DynamicArray<T>::getItem(int index, T* item)
{
	if (index < 0 || index > getLength())
		return false;

	item = &m_items[index];
	
	return true;
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < getLength(); i++)
		std::cout << m_items[i] << std::endl;
}