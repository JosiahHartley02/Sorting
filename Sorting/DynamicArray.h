#pragma once
template<typename T, int N>
class DynamicArray
{
public:
	void addItem(T item ,N index) { }
private:
	T *m_items;
	int m_length = N;
};
