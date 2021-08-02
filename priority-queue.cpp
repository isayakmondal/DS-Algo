#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PriorityQueue
{

private:
    vector<int> myPriorityQueue;
    int presentIndex = 0;

    void _upHeapify()
    {
    }

    void _downHeapify()
    {
    }

public:
    PriorityQueue(){

    };

    bool isEmpty()
    {
        return myPriorityQueue.size() == 0;
    }

    int getSize()
    {
        return myPriorityQueue.size();
    }
    int getMin()
    {
        if (isEmpty())
            return -1;

        return myPriorityQueue[0];
    }

    void insertValue(int val)
    {

        myPriorityQueue.push_back(val);
        int childIndex = myPriorityQueue.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (myPriorityQueue[childIndex] < myPriorityQueue[parentIndex])
            {
                swap(myPriorityQueue[childIndex], myPriorityQueue[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int removeMin()
    {
        if (isEmpty())
            return 0;

        int returnVal = myPriorityQueue[0];
        int lastIndex = myPriorityQueue.size() - 1;
        swap(myPriorityQueue[0], myPriorityQueue[lastIndex]);
        myPriorityQueue.pop_back();

        int currentIndex = 0;

        while (true)
        {
            int minIndex = currentIndex;
            int leftChildIndex = (2 * currentIndex) + 1;
            int rightChildIndex = (2 * currentIndex) + 2;
            //  minIndex = myPriorityQueue[leftChildIndex] < myPriorityQueue[rightChildIndex] ? leftChildIndex : rightChildIndex;
            if (leftChildIndex < myPriorityQueue.size() && myPriorityQueue[leftChildIndex] < myPriorityQueue[minIndex])
                minIndex = leftChildIndex;
            if (rightChildIndex < myPriorityQueue.size() && myPriorityQueue[rightChildIndex] < myPriorityQueue[minIndex])
                minIndex = rightChildIndex;
            if (currentIndex == minIndex)
                break;
            swap(myPriorityQueue[currentIndex], myPriorityQueue[minIndex]);
            currentIndex = minIndex;
        }

        return returnVal;
    }

   
};
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
                // if((leftChildIndex < size || rightChildIndex < size ) && leftChildIndex<rightChildIndex)
                // minIndex = leftChildIndex;
                // else
                // minIndex = rightChildIndex;


                if (leftChildIndex < size  && arr[leftChildIndex] < arr[minIndex])
                {
                    minIndex = leftChildIndex;
                }
                if (rightChildIndex < size  && arr[rightChildIndex] < arr[minIndex])
                {
                    minIndex = rightChildIndex;
                }

                if(minIndex == currentIndex) break;

                    swap(arr[currentIndex],arr[minIndex]);

                    currentIndex = minIndex;

            }
                
            }
            
        }
    

int main(int argc, char const *argv[])
{
    PriorityQueue p;
    p.insertValue(100);
    p.insertValue(10);
    p.insertValue(15);
    p.insertValue(4);
    p.insertValue(17);
    p.insertValue(21);
    p.insertValue(67);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMin() << " ";
    }

    // int arr[]={10,5,8,1,4};
    // inplaceHeapSort(arr,5);
    // for (auto &&i : arr)
    // {
    //     cout<<i<<endl;
    // }
    

    return 0;
}
