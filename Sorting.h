#ifndef SORTING_H
#define SORTING_H

#include <vector>

template <typename T>
std::vector<T>& insertionSort(std::vector<T>& V);



#endif


/**
 * Sorts a vector using the Insertion Sort algorithm.
 * In Insertion sort the vector is divided into two subsets - sorted subset and unsorted subset.
 * Initially, the sorted subset consists of only one first element at index 0. Then at each iteration
 * insertion sort removes the next element from the unsorted subset, finds the location it belongs to 
 * within the sorted subset and inserts it there. This is repeated until no input elements remain in the
 * unsorted subset.
 * 
 * The following is an Iterative implementation of the Insertion Sort algorithm
 * 
 * @tparam T the type of data stored in a vector
 * @param V non-empty vector
 * @return returns a sorted vector
 */
template <typename T>
std::vector<T>& insertionSort(std::vector<T>& V)
{
    T value {};
    int j { 1 };

    // since the element at position 0 is considered sorted, we start at index = 1
    for (int i { 1 }; i < V.size(); ++i)
    {
        value = V.at(i); // use V.at(i) instead of V[i] coz the former catches out of range errors
        j = i;

        // use index 'j' to find where the element V[i] belongs
        // within the sorted subset vector V[0...i-1]
        while (j > 0 && V.at(j - 1) > value)
        {
            V.at(j) = V.at(j - 1);
            --j;
        }

        V.at(j) = value;
    }

    return V;
}


