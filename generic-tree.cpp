#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<int> *> child;

    treeNode(T data)
    {
        this->data = data;
    }
    ~treeNode(){
        for (int i = 0; i < this->child.size(); i++)
        {
            delete child[i];
        }
        
    }
};

void printTree(treeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ": ";

    for (int i = 0; i < root->child.size(); i++)
    {
        cout << root->child[i]->data << ",";
    }
    cout << endl;

    for (int i = 0; i < root->child.size(); i++)
    {
        printTree(root->child[i]);
    }
}

treeNode<int> *takeInputLevel()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n;
        treeNode<int> *f = q.front();
        q.pop();
        cout << "Enter number of children of node " << f->data << endl;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "Enter data of " << i << " th child"
                 << " of node  " << f->data << endl;
            cin >> childData;
            treeNode<int> *newChild = new treeNode<int>(childData);
            q.push(newChild);
            f->child.push_back(newChild);
        }
    }

    return root;
}

void levelOrderPrint(treeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<treeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        treeNode<int> *f = q.front();
        q.pop();
        cout << f->data << " : ";

        for (int i = 0; i < f->child.size(); i++)
        {
            cout << f->child[i]->data << ",";
            q.push(f->child[i]);
        }
        cout << endl;
    }
}

int countNodes(treeNode<int> *root)
{

    int count = 1;

    for (int i = 0; i < root->child.size(); i++)
    {
        count = count + countNodes(root->child[i]);
    }
    return count;
}

int findHeight(treeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int maxHeight = 0;
    for (int i = 0; i < root->child.size(); i++)
    {
        //    height = height + max(findHeight(root->child[i]),height);

        maxHeight = max(maxHeight, findHeight(root->child[i]));
    }
    return maxHeight + 1;
}

void printLevelK(treeNode<int> *root, int k)
{

    if (root == NULL)
        return ;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->child.size(); i++)
    {
        printLevelK(root->child[i], k - 1);
    }
}

int countLeafNodes(treeNode<int> * root){

    if (root == NULL)
        return 0;

    if(root->child.size()==0){
        return 1;
    }
        int count=0; 
    for(int i=0;i<root->child.size();i++){

         count+=countLeafNodes(root->child[i]);

    }
    return count;

}

void preorder(treeNode<int> * root){

    if(!root)
    return;


    cout<<root->data<<endl;

    for (int i = 0; i < root->child.size(); i++)
    {
        preorder(root->child[i]);
    }
    
}
void postorder(treeNode<int> * root){

    if(!root)
    return;


    for (int i = 0; i < root->child.size(); i++)
    {
        preorder(root->child[i]);
    }
    
    cout<<root->data<<endl;
}

int main()
{

    // treeNode<int> *root = new treeNode<int>(1);
    // treeNode<int> *c1 = new treeNode<int>(2);
    // treeNode<int> *c2 = new treeNode<int>(3);

    // root->child.push_back(c1);
    // root->child.push_back(c2);
    treeNode<int> *root = takeInputLevel();
    // printTree(root);
    // levelOrderPrint(root);
    // cout << "Total no.of Nodes = " << countNodes(root);
    // cout << "Height of the tree is = " << findHeight(root);
    // printLevelK(root, 2);
    // cout<<countLeafNodes(root);
    delete root;
    root=NULL;
    preorder(root);
    // postorder(root);
    return 0;
}
