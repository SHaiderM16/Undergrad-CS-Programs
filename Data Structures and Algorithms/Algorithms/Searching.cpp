#include <iostream>
using namespace std;

// ---------------------------- Linear Search ----------------------------

int linearSearch(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// ---------------------------- Binary Search ----------------------------

int binarySearch(int array[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
        {
            return mid; // Target found
        }
        else if (array[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int recursiveBinarySearch(int array[], int left, int right, int target)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (array[mid] == target)
        {
            return mid;
        }

        // If target is smaller, search the left half
        if (array[mid] > target)
        {
            return recursiveBinarySearch(array, left, mid - 1, target);
        }

        // If target is larger, search the right half
        return recursiveBinarySearch(array, mid + 1, right, target);
    }

    return -1; // Target is not present in the array
}

// ---------------------------- Interpolation Search ----------------------------

bool isUniformlyDistributed(int array[], int size)
{
    int commonDifference = array[1] - array[0];

    // Check if difference between each pair of consecutive elements is same
    for (int i = 2; i < size; i++)
    {
        if ((array[i] - array[i - 1]) != commonDifference)
        {
            return false;
        }
    }

    return true;
}

int interpolationSearch(int array[], int sizeArray, int valueToFind)
{
    int start = 0, end = sizeArray - 1;

    while (start <= end && valueToFind >= array[start] && valueToFind <= array[end])
    {
        int pos = start + ((valueToFind - array[start]) * (end - start)) / (array[end] - array[start]);

        if (array[pos] == valueToFind)
            return pos;

        if (array[pos] < valueToFind)
            start = pos + 1;
        else
            end = pos - 1;
    }

    return -1;
}