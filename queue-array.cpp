#include <iostream>
#include <vector>

using namespace std;
template<typename T>

class Queue
{

    int *arr;
    vector<T> v;
    int front;
    int rear;
    int size = 0;
    int capacity;

public:
    Queue(int n)
    {
        capacity = n;
        arr = new T[capacity];
        // v.reserve(n);
        front = rear = -1;
        size = 0;
    };

    void push(T data)
    {
        if(size==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
           
        }
        rear=(rear+1)%capacity;
        arr[rear] = data;
        // v.push_back(data);
        size++;
    }

    bool isempty()
    {
        if (size==0)
            return true;
        else
            return false;
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front+1)%capacity;
        // v.pop_back();
        size--;
    }

    T getfront()
    {
        if (!isempty())
            return arr[front];
            // return v[front];
        else
            return 0;
    }

    T getrear()
    {
        if (!isempty())
            return arr[rear];
            // return v[rear];
        else
            return 0;
    }

    int getsize()
    {
        return size;
    }
    // void print()
    // {
    //     for (int i = front; i <= rear; i++)
    //     {
    //         cout << arr[i] << endl;
    //     }
    // }
};

int main()
{

    Queue<int> q(5);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.push(10);
    // q.push(11);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.push(6);
    // q.pop();
    // q.pop();

    // q.print();
    cout << q.getfront() << endl;
    cout << q.getrear() << endl;
    cout << q.getsize() << endl;
}