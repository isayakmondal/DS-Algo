#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
} *head = NULL, *tail = NULL;

void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void create()
{ //Using tail pointer
    int data;
    cout << "Insert Values. Press -1 to exit." << endl;
    cin >> data;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
}

int length()
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int lengthRec(node *head)
{

    if (head == NULL)
    {
        return 0;
    }

    return lengthRec(head->next) + 1;
}

bool search(int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return true;

        temp = temp->next;
    }
    return false;
}

bool searchRec(int val, node *head)
{

    if (head == NULL)
        return false;
    else if (head->data == val)
        return true;
    else
        return searchRec(val, head->next);
}

void printIthNode(int pos)
{

    node *temp = head;
    if (pos < 0)
    {
        cout << "Node does not exists" << endl;
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        if (temp != NULL)
            temp = temp->next;
    }
    if (temp != NULL)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Node does not exists" << endl;
        return;
    }
}

void insertAtIthPos(int val, int pos)
{
    if (pos < 0)
    {
        cout << "Cannot add in this position, enter other position." << endl;
        return;
    }
    node *temp = head;
    if (pos == 0)
    {
        node *newnode = new node(val);
        newnode->next = head;
        head = newnode;
        return;
    }
    int i = 0;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp)
    {
        node *newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        cout << "Cannot add in this position, enter other position." << endl;
        return;
    }
}

// void create(){  //Using head pointer
//     int data;
//     cout<<"Insert Values. Press -1 to exit."<<endl;
//     cin>>data;
//     while (data!=-1)
//     {
//         node *newnode = new node(data);
//         if(head==NULL){
//             head = newnode;
//             tail = newnode;
//         }
//         else
//         {
//             newnode->next = head;
//             head = newnode;
//         }
//         cin>>data;
//     }

// }
void deleteAtIthPos(int pos)
{
    if (pos < 0)
    {
        cout << "Cannot Delete! Enter a valid index " << endl;
        return;
    }
    int i = 0;
    node *temp1 = head, *temp2;
    if (pos == 0)
    {
        if (head == NULL)
            return;

        head = temp1->next;
        delete temp1;
        return;
    }
    while (i < pos - 1 && temp1->next != NULL)
    {
        temp1 = temp1->next;
        i++;
    }
    if (temp1->next)
    {
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    else
    {
        cout << "Cannot Delete! Enter a valid index " << endl;
        return;
    }
}

node *midOfLinkedList() //using fast and slow pointer approach
{
    node *slow = head, *fast = head;

        while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node * reverse(){
    node *current = head;
    node *prev = NULL;

    while (current!=NULL)
    {
        node *n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    
    return prev;
}

void removeKthFromEnd(int k){  //Using one traversal
    node *one,*two;
    one = two = head;
    while(k--)
    {
        two=two->next;
    }
    if(two==NULL){
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(two->next!=NULL){
        one = one->next;
        two = two->next;
    }
    
    node *temp;
    temp = one->next;
    one ->next = temp->next;
    delete temp;
}

int main()
{

    int choice, pos, value;

    cout << "Please enter your choice." << endl;
    while (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            print();
            break;
        case 3:
            cout << "Length = " << length();
            break;
        case 4:
            cout << "Enter the node position you want to print (O-based index)" << endl;
            cin >> pos;
            printIthNode(pos);
            break;
        case 5:
            cout << "Enter the data and position" << endl;
            cin >> value >> pos;
            insertAtIthPos(value, pos);
            break;
        case 6:
            cout << "Enter the position of the value to delete" << endl;
            cin >> pos;
            deleteAtIthPos(pos);
            break;
        case 7:
            cout << lengthRec(head) << endl;
            break;
        case 8:
            cout << "Enter the value you want to search for " << endl;
            cin >> value;
            if (search(value))
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
            break;
        case 9:
            cout << "Enter the value you want to search for " << endl;
            cin >> value;
            if (searchRec(value, head))
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
            break;
        case 10:
            // node * mid = midOfLinkedList();
            cout << midOfLinkedList()->data << endl;
            break;
        case 11:
            head = reverse();
            cout<<"Reversed Successfully"<<endl;
            break;
        case 12:
            cout<<"Enter kth node from the end"<<endl;
            cin>>value;
            removeKthFromEnd(value);
            cout<<"Deletion Successful!"<<endl;
            break;

        

        default:
            break;
        }
        cout << "Please enter your choice." << endl;
    }

    return 0;
}