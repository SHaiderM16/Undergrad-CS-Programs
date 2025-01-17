#include <iostream>
using namespace std;

// ---------------------------- Bubble Sort ----------------------------

void unoptimisedBubbleSortAscending(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // Sort in ascending
            // If previous greater than next
            if (array[j] > array[j + 1]) // (array[j] < array[j + 1]) for descending
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void optimisedBubbleSortAscending(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            // Sort in ascending
            // If previous greater than next
            if (array[j] > array[j + 1]) // (array[j] < array[j + 1]) for descending
            {
                swap(array[j], array[j + 1]);
                isSwapped = true;
            }
        }
        // Exits function whenever array becomes sorted
        if (isSwapped == false)
        {
            return;
        }
    }
}

// ---------------------------- Selection Sort ----------------------------

void selectionSortMin(int array[], int size)
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            // Find min element
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        swap(array[min], array[i]);
    }
}

void selectionSortMax(int array[], int size)
{
    int max;
    for (int i = 0; i < size - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < size; j++)
        {
            // Find max element
            if (array[j] > array[max])
            {
                max = j;
            }
        }

        swap(array[max], array[i]);
    }
}

// ---------------------------- Insertion Sort ----------------------------

void insertionSort(int array[], int size)
{
    int j;
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

// ---------------------------- Merge Sort ----------------------------

void merge(int arr[], int left, int mid, int right)
{
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    int *leftArray = new int[sizeLeft];
    int *rightArray = new int[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
    {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < sizeRight; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArray[i] <= rightArray[j]) // if (leftArray[i] >= rightArray[j]) for descending
        {
            arr[k] = leftArray[i];

            i++;
        }
        else
        {
            arr[k] = rightArray[j];

            j++;
        }
        k++;
    }

    // Add remaining elements of either left or right array
    while (i < sizeLeft)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < sizeRight)
    {
        arr[k] = rightArray[j];

        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int left, int right, string order)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, order);
        mergeSort(arr, mid + 1, right, order);

        merge(arr, left, mid, right);
    }
}

// ---------------------------- Quick Sort ----------------------------

int partition(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivot = arr[mid]; // Choose middle element as pivot

    int i = low, j = high;

    while (true)
    {
        while (arr[i] < pivot) // > for descending
        {
            i++;
        }

        while (arr[j] > pivot) // < for descending
        {
            j--;
        }

        if (i >= j) // If i crosses j
        {
            return j;
        }

        swap(arr[i], arr[j]);

        i++;
        j--;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);      // Sort left subarray
        quickSort(arr, pi + 1, high); // Sort right subarray
    }
}

// ---------------------------- Radix Sort ----------------------------

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSortAscending(int arr[], int size, int exp)
{
    int *output = new int[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

void countingSortDescending(int arr[], int size, int exp)
{
    int *output = new int[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 8; i >= 0; i--)
    {
        count[i] += count[i + 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSort(int arr[], int size, string order)
{
    int max = getMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        if (order == "Ascending" || order == "ascending")
        {
            countingSortAscending(arr, size, exp);
        }
        else if (order == "Descending" || order == "descending")
        {
            countingSortDescending(arr, size, exp);
        }
    }
}
