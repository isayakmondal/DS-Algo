#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int> &q){
    stack<int> s;

     while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

}

int main(){

    queue<int> q ;
    

    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    // cout << q.front() << endl;  
    // cout << q.back() << endl;
    // cout << q.size() << endl;
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }

   reverse(q);
    
    // cout << q.front() << endl;  
    // cout << q.back() << endl;
    // cout << q.size() << endl;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

}