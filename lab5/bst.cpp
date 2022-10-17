#include <iostream>
#include <string>
using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    // constructor
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// create binary tree node class
class BST
{
public:
    // constructor

    BST() { BinaryTreeNode *node = nullptr; }


    // functions
    BinaryTreeNode * Insert(BinaryTreeNode *node,int newKey);
    void PrintTree(BinaryTreeNode *node);
};

BinaryTreeNode * BST::Insert(BinaryTreeNode *node, int newKey) {
    //check if tree is empty, if so create new node at root
    if (node == nullptr)
    {
        node = new BinaryTreeNode(newKey);
        node->data = newKey;
        node->left = nullptr;
        node->right = nullptr;
    }
    // determining where to insert new key in subtree
    if (node->data > newKey) //insert in left subtree
    {
        node->left = Insert(node->left, newKey);
    }
    else if (node->data < newKey) //insert in right subtree
    {
        node->right = Insert(node->right, newKey);
    }
    // if key is a duplicate

    return node;
}
// print tree structure in-order
void BST::PrintTree(BinaryTreeNode *node) {
    string charLeft = "e";
    string charRight = "e";
    // check if tree is empty
    if (node == nullptr)
    {
        cout << "Empty tree, insert a node" << endl;
        return;
    }
    // check if node is null
    if (node->left != nullptr)
    {
        charLeft = to_string(node->left->data);
    }
    if (node->right != nullptr)
    {
        charRight = to_string(node->right->data);
    }


    // print left subtree
    if (node->left != nullptr)
    {
        PrintTree(node->left);
    }
    // print root
    cout << to_string(node->data) << " " << "(" << charLeft << ", " << charRight << "); ";
    // print right subtree
    if (node->right != nullptr)
    {
        PrintTree(node->right);
    }
}



int main(int argc, char const *argv[])
{
    int arr[] = {6,4,8,2,7,3,1, 69};
    int len = sizeof(arr)/sizeof(arr[0]);
    // initialize tree class
    BST T;
    BinaryTreeNode *node = nullptr;

    //insert keys into the tree
    for (int i = 0; i < len; i++)
    {
        node = T.Insert(node, arr[i]);
    }
    // print tree
    T.PrintTree(node);
    return 0;
}
