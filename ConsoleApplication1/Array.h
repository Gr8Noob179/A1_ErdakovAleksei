#pragma once
#include <cassert>

template<class T>
class Array
{
public:
    Array(int size, int growBy = 1) :
        m_array(nullptr), m_maxSize(0), m_growSize(0), m_numElements(0)
    {
        if (size)
        {
            m_maxSize = size;
            m_array = new T[m_maxSize];
            memset(m_array, 0, sizeof(T) * m_maxSize);

            m_growSize = ((growBy > 0) ? growBy : 0);
        }
    }

    virtual ~Array()
    {
        if (m_array != nullptr)
        {
            delete[] m_array;
            m_array = nullptr;
        }
    }

    virtual void push(T val) = 0;

    void pop()
    {
        if (m_numElements > 0)
        {
            m_numElements--; 
        }
    }

    void remove(int index)
    {
        assert(m_array != nullptr);

        if (index >= m_numElements)
        {
            return;
        }

        for (int i = index; i < m_numElements; i++)
        {
            if (i + 1 < m_numElements)
            {
                m_array[i] = m_array[i + 1];
            }
        }

        m_numElements--;
    }

    T& operator[](int index)
    {
        assert(m_array != nullptr && index < m_numElements);
        return m_array[index];
    }

    void clear()
    {
        m_numElements = 0;
    }

    virtual int search(T searchKey) const = 0;

    int GetSize() const { return m_numElements; }

    int GetMaxSize() const { return m_maxSize; }

    int GetGrowSize() const { return m_growSize; }

    void SetGrowSize(int val)
    {
        assert(val >= 0);
        m_growSize = val;
    }

protected:
    bool Expand()
    {
        if (m_growSize <= 0)
        {
            return false;
        }

        T* temp = new T[m_maxSize + m_growSize];
        assert(temp != nullptr);

        memcpy(temp, m_array, sizeof(T) * m_maxSize);

        delete[] m_array;
        m_array = temp;
        m_maxSize += m_growSize;

        return true;
    }

protected:
    T* m_array;
    int m_maxSize;
    int m_growSize;
    int m_numElements;
};