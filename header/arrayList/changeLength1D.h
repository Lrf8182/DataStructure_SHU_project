#pragma once
#include "../myExceptions.h"
#include <algorithm>

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
    if (newLength < 0) {
        throw illegalParameterValue("new length must be >= 0");
    }

    T* temp = new T[newLength];              // new array
    int number = std::min(oldLength, newLength);  // number to copy
    std::copy(a, a + number, temp);
    delete[] a;                             // deallocate old memory
    a = temp;
}
