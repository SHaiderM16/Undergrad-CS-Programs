#include <iostream>
using namespace std;

#define MAX_HEAP_SIZE 1000

// Function to heapify for Max Heap
void maxHeapify(int array[], int arraySize, int maxElement)
{
    int largest = maxElement;
    int left = 2 * maxElement + 1;
    int right = 2 * maxElement + 2;

    if (left < arraySize && array[left] > array[largest])
        largest = left;

    if (right < arraySize && array[right] > array[largest])
        largest = right;

    if (largest != maxElement)
    {
        swap(array[maxElement], array[largest]);
        maxHeapify(array, arraySize, largest);
    }
}

// Function to heapify for Min Heap
void minHeapify(int array[], int arraySize, int minElement)
{
    int smallest = minElement;
    int left = 2 * minElement + 1;
    int right = 2 * minElement + 2;

    if (left < arraySize && array[left] < array[smallest])
        smallest = left;

    if (right < arraySize && array[right] < array[smallest])
        smallest = right;

    if (smallest != minElement)
    {
        swap(array[minElement], array[smallest]);
        minHeapify(array, arraySize, smallest);
    }
}

// Build Max Heap
void buildMaxHeap(int array[], int arraySize)
{
    for (int i = (arraySize / 2) - 1; i >= 0; i--)
        maxHeapify(array, arraySize, i);
}

// Build Min Heap
void buildMinHeap(int array[], int arraySize)
{
    for (int i = (arraySize / 2) - 1; i >= 0; i--)
        minHeapify(array, arraySize, i);
}

// Heap Sort
void heapSort(int array[], int arraySize)
{
    buildMaxHeap(array, arraySize);

    for (int i = arraySize - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}

// Insert into Heap
void insertElement(int array[], int &arraySize, int value, bool isMaxHeap)
{
    array[arraySize++] = value;

    for (int i = (arraySize - 1) / 2; i >= 0; i--)
    {
        if (isMaxHeap)
        {
            maxHeapify(array, arraySize, i);
        }
        else
        {
            minHeapify(array, arraySize, i);
        }
    }
}
// Delete root from Heap
void deleteRoot(int array[], int &arraySize, bool isMaxHeap)
{
    if (arraySize == 0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }
    array[0] = array[--arraySize];

    if (isMaxHeap)
    {
        maxHeapify(array, arraySize, 0);
    }
    else
    {
        minHeapify(array, arraySize, 0);
    }
}

// Search in Heap
bool searchHeap(int array[], int arraySize, int key)
{
    for (int i = 0; i < arraySize; i++)
        if (array[i] == key)
            return true;
    return false;
}

// Print Heap
void printHeap(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
        cout << array[i] << " ";
    cout << endl;
}