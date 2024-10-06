#pragma once
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T>
{
public:
    UnorderedArray(int size, int growBy = 1) :
        Array<T>(size, growBy) {}

    void push(T val) override
    {
        assert(this->m_array != nullptr);

        if (this->m_numElements >= this->m_maxSize)
        {
            this->Expand();
        }

        this->m_array[this->m_numElements] = val;
        this->m_numElements++;
    }

    int search(T searchKey) const override
    {
        assert(this->m_array != nullptr);

        for (int i = 0; i < this->m_numElements; i++)
        {
            if (this->m_array[i] == searchKey)
            {
                return i; 
            }
        }

        return -1; 
    }
};