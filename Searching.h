#ifndef SEARCHING_H
#define SEARCHING_H

template <typename T>
int linearSearch(T* const A, int size, const T& x);

template <typename T>
int binarySearchIterative(T* const A, int size, const T& x);

template <typename T>
int binarySearchRecursive(T* const A, int low, int high, const T& x);

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
int linearSearch(T* const A, int size, const T& x)
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


/**
 * Finds the position/index of an element in an array using the Binary Search algorithm.
 * Binary search is a divide and conquer algorithm. It first divides a large array into smaller subarrays
 * and then recursively (or iteratively) operate on the subarrays. Instead of working on both subarrays, it
 * discards one subarray and continues on the second subarray, which will be further sub-divided if the
 * target element has not been found. 
 * The array should be sorted first before using Binary search.
 * The following is an Iterative implementation of the Binary Search algorithm
 * 
 * @tparam T the type of data stored in an array
 * @param A non-empty array
 * @param size length of array
 * @param x target value to find in array
 * @return index of target value, or -1 if not found
 */
template <typename T>
int binarySearchIterative(T* const A, int size, const T& x)
{
    // define our starting search space
    int low { 0 };
    int high { size - 1 };

    // loop until the search space is exhausted
    while (low <= high)
    {
        // find the mid-value - N.B: To avoid overflow when (low+high) > 2147483647 (max value for int)
        // use the following statement instead of int mid { (low + high) / 2 }
        int mid { low + (high - low) / 2 };

        // check if mid-value is equal to our target value
        if (x == A[mid])
        {
            return mid;
        } 
        // If the target is less than the middle element, discard all elements in the right search space
        // including the middle element
        else if (x < A[mid])
        {
            high = mid - 1;
        }
        // If the target is greater than the middle element, discard all elements in the left search space
        // including the middle element
        else 
        {
            low = mid + 1;
        }
    }

    // if the target does not exist in the array
    return -1;
}

/**
 * Finds the position/index of an element in an array using the Binary Search algorithm.
 * Binary search is a divide and conquer algorithm. It first divides a large array into smaller subarrays
 * and then recursively (or iteratively) operate on the subarrays. Instead of working on both subarrays, it
 * discards one subarray and continues on the second subarray, which will be further sub-divided if the
 * target element has not been found. 
 * The array should be sorted first before using Binary search.
 * The following is a Recursive implementation of the Binary Search algorithm
 * 
 * @tparam T the type of data stored in an array
 * @param A non-empty array
 * @param low start index of array/sub-array
 * @param high highest index of array/sub-array
 * @param x target value to find in array
 * @return index of target value, or -1 if not found
 */
template <typename T>
int binarySearchRecursive(T* const A, int low, int high, const T& x)
{
    // Base condition - search space is exhausted
    if (low > high)
        return -1;
    
    // find the mid-value in the search space and compare it with the target value
    int mid { low + (high - low) / 2 };

    // Base condition (target value is found)
    if (x == A[mid])
    {
        return mid;
    }
    // discard all elements in the right search space, including the middle element
    else if (x < A[mid])
    {
        return binarySearchRecursive(A, low, mid -1, x);
    }
    // discard all elements in the left search space, including the middle element
    else 
    {
        return binarySearchRecursive(A, mid + 1, high, x);
    }
}
