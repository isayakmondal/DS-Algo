#include <iostream>
#include <queue>

using namespace std;

void k_sorted_array(int *arr, int size, int k)
{

    priority_queue<int> maxHeap;

    for (int start = 0; start < size; start++)
    {
        int i = start + k;

        if (start == 0)
        {

            for (int j = 0; j < k; j++)
            {
                maxHeap.push(arr[j]);
            }
        }
        else if (i <= size)
        {
            maxHeap.push(arr[i - 1]);
        }
        arr[start] = maxHeap.top();
        maxHeap.pop();
    }
}

int *k_smallest_element(int *arr, int size, int k)
{
    static int buff[10];

    priority_queue<int> myHeap;

    for (int i = 0; i < k; i++)
    {
        myHeap.push(arr[i]);
    }
    for (int j =k; j < size; j++)
    {
        if(arr[j]<myHeap.top()){
            myHeap.pop();
            myHeap.push(arr[j]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        buff[i]=myHeap.top();
        myHeap.pop();
    }


    return buff;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {12,7,5,9,4};
    int arr[] = {5,6,9,12,3,13,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // k_sorted_array(arr, size, k);
    int *p;
    p = k_smallest_element(arr, size, k);
    for (int i = 0; i < k; i++)
    {
        cout << p[i] << " ";
    }

    // for (auto &i : arr)
    // {
    //     cout << i << " ";
    // }

    return 0;
}
