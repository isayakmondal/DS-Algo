#include <iostream>

using namespace std;
 
int k = 1;
class node
{
 
public:
    
    int pos;
    node *next;
    node()
    {
        this->pos = k++;
        this->next = NULL;
    }
   
} *head = NULL, *tail = NULL;
 
 
void createNodes(int n)                     //Creating nodes and initializing the positions
{
 
    while (n--)
    {
        node *newnode = new node();
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
            tail->next = head;
    }
}
 
int josephus(int n, int k)
{
    createNodes(n);                      //Creating n nodes of circular singly linked list
    node *temp1 = head, *temp2;
    while (temp1->next!=temp1)
    {
        int count = k - 2;
        while (count--)                  //making temp1 point to the previous node of the note to be deleted
        {
            temp1 = temp1->next;
        }
 
        temp2 = temp1->next;
        temp1->next = temp2->next;      //creating link between previous and next node of the deleted node
        delete temp2;                   //deleting the node
                                            //setting the address to nullptr
 
        // if (temp1->next!=temp1)
        
            temp1 = temp1->next;
        
    }
    return temp1->pos;        //Printing the safe position
}
 
int main(){
    
    int n,k;
    cout<<"Enter n and k"<<endl;
    cin>>n>>k;  
    cout<<"The safe position is: "<<josephus(n,k)<<endl;
   
    
    return 0;
}


/*Code for debugging*/

// #include <iostream>
// using namespace std;

// int k = 1;
// class node
// {

// public:
//     int data;
//     int pos;
//     node *next;

//     node()
//     {
//         this->data = 0;
//         this->pos = k++;
//         this->next = NULL;
//     }
//     node(int data)
//     {

//         this->data = data;
//         this->pos = k++;
//         this->next = NULL;
//     }
// } *head = NULL, *tail = NULL;

// void create()
// { //Using tail pointer
//     int data;
//     cout << "Insert Values. Press -1 to exit." << endl;
//     cin >> data;
//     while (data != -1)
//     {
//         node *newnode = new node(data);
//         if (head == NULL)
//         {
//             head = newnode;
//             tail = newnode;
//             tail->next = newnode;
//         }
//         else
//         {
//             tail->next = newnode;
//             tail = newnode;
//             tail->next = head;
//         }
//         cin >> data;
//     }
// }
// void createNodes(int n)
// {

//     while (n--)
//     {
//         node *newnode = new node();
//         if (head == NULL)
//         {
//             head = newnode;
//             tail = newnode;
//             tail->next = head;
//         }
//         else
//         {
//             tail->next = newnode;
//             tail = newnode;
//             tail->next = head;
//         }
//     }
// }

// void print()
// {
//     node *temp = head;
//     while (temp->next != head)
//     {
//         cout << temp->pos << "->";
//         temp = temp->next;
//     }
//     cout << temp->pos << endl;
// }

// int josephus(int n, int k)
// {
//     createNodes(n); //Creating n nodes of circular singly linked list
//     node *temp1 = head, *temp2;
//     while (temp1->next!=temp1 )
//     {
//         int new_k = k - 2;
//         while (new_k--) //making temp1 point to the previous node of the note to be deleted
//         {
//             temp1 = temp1->next;
//         }

//         temp2 = temp1->next;
//         temp1->next = temp2->next; //creating link between previous and next node of the deleted node
//         delete temp2;              //deleting the node
//         temp2 = NULL;           //setting the address to nullptr

//         if (temp1->next!=temp1)
//         {
//             temp1 = temp1->next;
//         }
//     }
//     return temp1->pos;  //Printing the safe position
// }

// int main()
// {

//     int choice, pos, value,n,k;

//     cout << "Please enter your choice." << endl;
//     while (cin >> choice)
//     {
//         switch (choice)
//         {
//         case 1:
//             create();
//             break;
//         case 2:
//             print();
//             break;
//         case 3:
//             cout << "Enter n and k" << endl;
//             cin >> n >> k;
//             cout<<"The safe position is : "<<josephus(n,k)<<endl;
//             break;
//         case 4:
//             cout << "Enter n" << endl;
//             cin >> pos;
//             createNodes(pos);
//             break;

//         default:
//             break;
//         }
//         cout << "Please enter your choice." << endl;
//     }
// }