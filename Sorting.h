#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <utility>    // for std::swap

// templated type alias for a function pointer 
template <typename T>
using ComparisonFcn = bool(*)(const T&, const T&);


template <typename T>
bool ascending(const T& x, const T& y);

template <typename T>
bool descending(const T& x, const T& y);

template <typename T>
std::vector<T>& insertionSort(std::vector<T>& V, ComparisonFcn<const T&> cFcn = ascending);

template <typename T>
std::vector<T>& selectionSort(std::vector<T>& V, ComparisonFcn<const T&> cFcn = ascending);


#endif

/**
 * Compares two values and returns true/false whether the first value is greater than
 * the second value. This helps in sorting values in ascending order.
 *  
 * @tparam T the type of data to be compared
 * @param x first value
 * @param y second value
 * @return returns true/false whether x is greater than y
 */
template <typename T>
bool ascending(const T& x, const T& y)
{
    return x > y; // swap if the first element is greater than the second
}

/**
 * Compares two values and returns true/false whether the first value is smaller than
 * the second value. This helps in sorting values in descending order.
 *  
 * @tparam T the type of data to be compared
 * @param x first value
 * @param y second value
 * @return returns true/false whether x is less than y
 */
template <typename T>
bool descending(const T& x, const T& y)
{
    return x < y; // swap if the second element is greater than the first
}

/**
 * Sorts a vector using the Insertion Sort algorithm either in ascending/descending order.
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
 * @param cFcn pointer to a function that decides the order of sorting e.g ascending/descending
 * @return returns a sorted vector
 */
template <typename T>
std::vector<T>& insertionSort(std::vector<T>& V, ComparisonFcn<const T&> cFcn)
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
        while (j > 0 && cFcn(V.at(j - 1), value))
        {
            V.at(j) = V.at(j - 1);
            --j;
        }

        V.at(j) = value;
    }

    return V;
}

/**
 * Sorts a vector using the Selection Sort algorithm either in ascending/descending order.
 * The idea of Selection sort is to divide the vector into two subsets - sorted and unsorted. Initially
 * the sorted subset is empty, and the unsorted subset is the entire input vector. The algorithm 
 * proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted
 * subset, swapping it with the leftmost element (putting it in sorted order), and moving the subset
 * boundaries one element to the right. 
 * 
 * If you want to use your own order for sorting e.g. sort the even numbers first all you have 
 * to do is write the function for it with the same signature as the defined function pointer.
 * 
 * @tparam T the type of data stored in a vector
 * @param V non-empty vector
 * @param cFcn pointer to a function that decides the order of sorting e.g ascending/descending
 * @return returns a sorted vector
 */
template <typename T>
std::vector<T>& selectionSort(std::vector<T>& V, ComparisonFcn<const T&> cFcn)
{
    // iterate through each element 
    for (int startIndex { 0 }; startIndex < (V.size() - 1); ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far
        // depending on whether we are sorting in ascending or descending order
        int bestIndex { startIndex };

        // Look for smallest/largest element remaining in the vector (starting at startIndex+1)
        for (int currentIndex { startIndex + 1 }; currentIndex < V.size(); ++currentIndex)
        {
            // if the current element is smaller/larger than our previously found smallest/largest
            if (cFcn(V.at(bestIndex), V.at(currentIndex))) // Comparison done here
            {
                // This is now the new smallest/largest number for this iteration
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest/largest element
        std::swap(V.at(startIndex), V.at(bestIndex));
    }

    return V;
}
