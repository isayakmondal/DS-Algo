#include <iostream>

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
class BST
{
private:
    BTNode<int> *root;

    bool hasData(BTNode<int> *root, int data)
    {

        if (!root)
            return false;

        if (root->data == data)
            return true;
        else if (data < root->data)
        {
            return hasData(root->left, data);
        }
        else 
        {
            return hasData(root->right, data);
        }
    }

    BTNode<int> *insertData(BTNode<int> *root, int data)
    {

        if (!root)
        {
            BTNode<int> *newnode = new BTNode<int>(data);
            return newnode;
        }

        if (data < root->data)
        {
            root->left = insertData(root->left, data);
        }
        else
        {
            root->right = insertData(root->right, data);
        }

        return root;
    }
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
    BTNode<int> * findRightMin(BTNode<int> * root){
        if(!root) return nullptr;
        if(!root->left) return root;
        return findRightMin(root->left);
    }

    BTNode<int> * deleteData(BTNode<int> *root,int data){

        if(!root) return nullptr;

        if(root->data == data){
        if(!root->left && !root->right){
            delete root;
            root = nullptr;
            return nullptr;
        }
        else if(root->left && !root->right){
            BTNode<int> *temp = root->left;
            delete temp;
            return root->left->left;

        }
        else if(!root->left && root->right){
            BTNode<int> *temp = root->right;
            delete temp;
            return root->right->right;

        }

        else if(root->left && root->right){
            BTNode<int> *temp= findRightMin(root->right);
            root->data = temp->data;
            root->right = deleteData(root->right,root->data);
        }
        }


    }

public:
    BST() { root = nullptr; }
    ~BST() { delete root; }

    void insertData(int data)
    {
        root = insertData(root, data);
    }
    void deleteData(int data)
    {
        deleteData(root,data);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void printTree()
    {
        printRecursive(root);
    }
};

int main(){

    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(7);
    b.insertData(12);
    b.insertData(13);
    b.insertData(15);

    b.printTree();
    // cout<<b.hasData(0);
}