#ifndef SEARCHING_H
#define SEARCHING_H

template <typename T>
T linearSearch(T* const A, int size, const T& x);

#endif

/**
 * Finds the position/index of an element in an array using the Linear Search algorithm.
 * Linear search compares every element in the array to the target until we get to the end 
 * of the array or we encounter the target before hand. The array or data structure does not 
 * need to be sorted first
 * 
 * @tparam T the type of data stored in an array
 * @param A non-empty array
 * @param size length of array
 * @param x target value to find in array
 * @return index of target value, or -1 if not found
 */
template <typename T>
T linearSearch(T* const A, int size, const T& x)
{
    // check that the pointer is valid
    if (!A)
        return -1;

    for (int index { 0 }; index < size; ++index)
    {
        // return index if target is found in array
        if (x == A[index])
            return index;
    }

    // return -1 if target value is not found
    return -1;
}