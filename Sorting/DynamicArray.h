#pragma once
template<typename T>
class DynamicArray
{
public:
    DynamicArray<T>()
    {
        m_items = new T[m_length];
    }

    ~DynamicArray<T>()
    {
        delete[] m_items;
    }

    void push(T item)
    {
        T* temp = new T[m_length + 1];
        for (int i = 0; i < m_length; i++)
            temp[i] = m_items[i];
        temp[m_length] = item;
        m_items = temp;
        m_length++;
    }

    bool remove(T item)
    {
        for (int i = 0; i < m_length; i++)
        {
            if (m_items[i] == item)
            {
                for (int n = i; n < m_length; n++)
                {
                    m_items[n + i] = m_items[n + i + 1];
                }
                m_length--;
                return true;
            }
        }
        return false;
    }

    T pop()
    {
        T item = m_items[m_length - 1];
        remove(item);
        return item;
    }

    T get(int index) { return m_items[index]; }

    void sort()
    {
        // Bubble sort
        for (int i = 0; i < m_length; i++)
        {
            for (int j = m_length; j > i; j--)
            {
                if (m_items[i] > m_items[j - 1])
                {
                    int temp = m_items[i];
                    m_items[i] = m_items[j - 1];
                    m_items[j - 1] = temp;
                }
            }
        }
    }

    int getLength() { return m_length; }

private:
    T* m_items;
    int m_length = 0;
};