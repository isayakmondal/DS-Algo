#include <iostream>
using namespace std;


/*

    This is min Heap , so the result is in descending order.
    If we use max Heap, the result will be in ascending order.
    We just have to change every "<" to ">" to change it to min heap.

    
*/

void inplaceHeapSort(int *arr, int size)
{

    int childIndex, parentIndex = 0;

    for (int i = 1; i < size; i++)
    {
        childIndex = i;

        while (childIndex > 0)
        {
            parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                swap(arr[childIndex], arr[parentIndex]);
                childIndex = parentIndex;
            }

            else
            {
                break;
            }
        }
    }

    while (size)
    {
        swap(arr[0], arr[size - 1]);
        size--;

        int currentIndex = 0;
        while (true)
        {
            int leftChildIndex = (2 * currentIndex) + 1;
            int rightChildIndex = (2 * currentIndex) + 2;
            int minIndex = currentIndex;

            if (leftChildIndex < size && arr[leftChildIndex] < arr[minIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && arr[rightChildIndex] < arr[minIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == currentIndex)
                break;

            swap(arr[currentIndex], arr[minIndex]);

            currentIndex = minIndex;
        }
    }
}
int main()
{
    int input[] = {10, 5, 8, 1, 4};
    inplaceHeapSort(input, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}
