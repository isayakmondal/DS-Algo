#include <iostream>
#include<vector>
using namespace std;

template <typename T>
class stack
{
private:
    int *arr;
    vector<T> v;
    int top;
    int capacity;

public:
    stack()
    {   
        // capacity = 5;
        // arr = new int[capacity];
        v.reserve(30);
        top = -1;
    }

    stack(int capacity)
    {
        // arr = new int[capacity];
        top = -1;
    }

    void push(T val)
    {
        // if (top == (capacity-1))
        // {
        //     capacity = 2 * capacity;
        //     int *newarr = new int[capacity];
        //     for (int i = 0; i <= top; i++)
        //     {
        //         newarr[i] = arr[i];
        //     }
        //     delete[] arr;
        //     arr = newarr;
        // }
        // top++;
        // arr[top] = val;
        top++;
        v.push_back(val);
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
        v.pop_back();
    }

    bool isEmpty()
    {
        if (top < 0)
            return true;
        else
            return false;
    }

    T topElement()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
            return v[top];
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    void size(){
        if(isEmpty()) {cout<<"Stack is empty"<<endl; return;}
        cout<<"Size is "<<v.size()<<endl;
    }
};

int main()
{
    stack<double> s;
    s.push(2.223);
    // s.push(4);
    // s.push(6);
    // s.pop();
    // for (int i = 0; i < 10; i++)
    // {
    //     s.push(i);
    // }
    

    s.print();
    s.size();
    cout<<s.topElement()<<endl;
    // s.pop();
    // cout<<s.topElement()<<endl;
    // cout<<s.topElement();
    return 0;
}