#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;
template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;
    BTNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    };
    ~BTNode()
    {
        delete left;
        delete right;
    };
};

void printRecursive(BTNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << ":";
    if (root->left)
    {
        cout << "L:" << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R:" << root->right->data << " ";
    }

    cout << endl;

    printRecursive(root->left);
    printRecursive(root->right);
}

BTNode<int> *takeInputRecursive()
{

    int rootData;
    cout << "Enter data  " << endl;
    cin >> rootData;

    if (rootData == -1)
        return nullptr;

    BTNode<int> *root = new BTNode<int>(rootData);
    BTNode<int> *leftChild = takeInputRecursive();
    BTNode<int> *rightChild = takeInputRecursive();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

BTNode<int> *takeInputLevel()
{

    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    BTNode<int> *root = new BTNode<int>(rootData);
    queue<BTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode<int> *temp = q.front();
        q.pop();
        int leftData, rightData;
        cout << "Enter data of left child of " << temp->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BTNode<int> *leftNode = new BTNode<int>(leftData);
            temp->left = leftNode;
            q.push(leftNode);
        }
        else
        {
            temp->left = nullptr;
        }
        cout << "Enter data of right child of " << temp->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BTNode<int> *rightNode = new BTNode<int>(rightData);
            temp->right = rightNode;
            q.push(rightNode);
        }
        else
        {
            temp->right = nullptr;
        }
    }
    return root;
}

int countNodes(BTNode<int> *root){


    
    if(root==NULL)
    return 0;

    return countNodes(root->left) + countNodes(root->right) +1;
}

void inorder(BTNode<int> * root){

    if(!root)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(BTNode<int> * root){

    if(!root)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BTNode<int> * root){

    if(!root)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(BTNode<int>*root){

    if(!root)
    return 0;

    return max(height(root->left),height(root->right))+1;
}

bool findANode(BTNode<int> * root,int key){

    if(!root) return false;
    if(root->data == key) return true;

    return findANode(root->left,key) || findANode(root->right,key);
}

int minValue(BTNode<int> * root){

    if(!root) return INT_MAX;

    // if(root->data<minimum){  //wrong, take a look later!
    //     minimum=root->data;
    //     // return minimum;
    // }
    return min(root->data,min(minValue(root->left),minValue(root->right)));
}
int maxValue(BTNode<int> * root){

    if(!root) return INT_MIN;

    return max(root->data,max(maxValue(root->left),maxValue(root->right)));
}


int countLeafNodes(BTNode<int> * root){

    if(!root) return 0;

    if(!root->left && !root->right) return 1;

    return countLeafNodes(root->left)+countLeafNodes(root->right);
}

vector<int> rootToNode(BTNode<int>*root, int val){

        vector<int> v;
    if(!root){
        v.empty();
        return {};
    }
        v.push_back(root->data);
    if(root->data==val){
        return v;
    }

    rootToNode(root->left,val);
    rootToNode(root->right,val);


}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1

int main()
{

    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *leftChild = new BTNode<int>(2);
    // BTNode<int> *rightChild = new BTNode<int>(3);

    // root->left = leftChild;
    // root->right = rightChild;

    // BTNode<int> *root = takeInputRecursive();
    BTNode<int> *root = takeInputLevel();

    // printRecursive(root);
    // cout<<countNodes(root);
    // inorder(root);
    // preorder(root);
    // postorder(root);
    // cout<<height(root);
    // cout<<findANode(root,7);
    // cout<<minValue(root);
    // cout<<maxValue(root);
    // cout<<countLeafNodes(root);
    vector<int> v = rootToNode(root,5);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}

