#include <iostream>
using namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};
template<typename T>
class Queue
{

    int size;
    Node<T> *front;
    Node<T> *rear;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    void push(T data)
    {
        Node<T> *newnode = new Node<T>(data);
        if (front == NULL)
        {
            front = rear = newnode;
            size++;
            return;
        }
        rear->next = newnode;
        rear = newnode;
        size++;
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        temp = NULL;
        size--;
    }

    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    T getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->data;
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue<float> q;
    // q.push(2.2);
    // q.push(4.4);
    // q.push(6.6);
    // q.push(8.8);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.getSize() << endl;

//     q.push(10);
//  q.push(20);
//  q.push(30);
//  q.push(40);
//  q.push(50);
//  q.push(60);
//  q.push(70);
//  cout<<q.getFront()<<endl;
//  q.pop();
//  q.pop();
//  q.pop();
//  cout<<q.getFront()<<endl;
//  cout<<q.getSize()<<endl;
//  cout<<q.isEmpty()<<endl;
//  q.push(60);
//  q.push(70);

//  q.pop();
//  q.pop();
//  cout<<q.getFront()<<endl;
//  cout<<q.getSize()<<endl;

//  while(!q.isEmpty()){
//     cout<<q.getFront()<<endl;
//     q.pop();
//  }
//  cout<<q.getSize()<<endl;
//  cout<<q.isEmpty()<<endl;

    return 0;
}