#include <iostream>

using namespace std;
template <typename T>
class Node
{

public:
    T data;
    Node<T> *next;
    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    };
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(T val)
    {
        Node<T> *newnode = new Node<T>(val);
        newnode->next = head;
        head = newnode;
        size++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (head)
            return false;
        else
            return true;
    }
    T top()
    {
        if (!isEmpty())
            return head->data;
        else
        {
            cout << "Stack is empty" << endl;
        }
        return 0;
    }
};

int main()
{
    Stack<int> s;
    s.push(2);
    // s.push(4);
    // s.push(6);
    s.pop();
    cout << s.top() << endl;
    cout << s.getsize() << endl;

    return 0;
}
