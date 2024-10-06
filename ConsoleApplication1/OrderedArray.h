#pragma once
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:
    OrderedArray(int size, bool allowDuplicates = true, int growBy = 1) :
        Array<T>(size, growBy), m_allowDuplicates(allowDuplicates) {}

    void push(T val) override
    {
        assert(this->m_array != nullptr);

        if (!m_allowDuplicates && search(val) != -1)
        {
            return; 
        }

        if (this->m_numElements >= this->m_maxSize)
        {
            this->Expand();
        }

        int i, k;
        for (i = 0; i < this->m_numElements; i++)
        {
            if (this->m_array[i] > val)
            {
                break;
            }
        }

        for (k = this->m_numElements; k > i; k--)
        {
            this->m_array[k] = this->m_array[k - 1];
        }

        this->m_array[i] = val;
        this->m_numElements++;
    }

    int search(T searchKey) const override
    {
        assert(this->m_array != nullptr);

        int lowerBound = 0;
        int upperBound = this->m_numElements - 1;
        int current = 0;

        while (lowerBound <= upperBound)
        {
            current = (lowerBound + upperBound) >> 1;

            if (this->m_array[current] == searchKey)
            {
                return current;
            }
            else if (this->m_array[current] < searchKey)
            {
                lowerBound = current + 1;
            }
            else
            {
                upperBound = current - 1;
            }
        }

        return -1;
    }

private:
    bool m_allowDuplicates;
};