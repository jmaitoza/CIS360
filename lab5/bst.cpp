/*
 * Message to TA Josh. I don't know how much C++ you know, but I'm tying to learn it as I go, as I need to use it in senior design.
 * If you see any egregious errors, please let me know or anything that is bad C++ practice. Thanks!
 * Also if you know CMake and ever have the chance to explain it better that would be great.
 */

#include <iostream>
#include <string>
using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    int nv;

    // constructor
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        nv = 0;
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
    void RangeQuery(BinaryTreeNode *node, int keyLow, int keyHigh);
    void TreeSelect(BinaryTreeNode *node, int index);
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
        node->nv++; //increment node value for TreeSelect method
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

// Range Query on BST
void BST::RangeQuery(BinaryTreeNode *node, int keyLow, int keyHigh) {
    if (node == nullptr)
    {
        return;
    }
    // check if node is in range
    if (node->data <= keyHigh && node->data >= keyLow)
    {
        RangeQuery(node->left, keyLow, keyHigh);
        RangeQuery(node->right, keyLow, keyHigh);
        cout << node->data << ", ";
    }
    else if (node->data < keyLow)
    {
        RangeQuery(node->right, keyLow, keyHigh);
    }
    else if (node->data > keyHigh)
    {
        RangeQuery(node->left, keyLow, keyHigh);
    }

}

// return the item with the ith smallest key
void BST::TreeSelect(BinaryTreeNode *node, int index) {
   if (node == nullptr)
   {
       cout << "Error - index out of range" << endl;
       return;
   }
   int w = node->nv + 1;
   // check if current node is the ith smallest key
   if (w == index)
   {
       cout << "The item with the " << index << "th smallest key is " << node->data << endl;
   }
   // check if index is in left subtree
   else if (index < w)
   {
       TreeSelect(node->left, index);
   }
   // check if index is in right subtree
   else
   {
       TreeSelect(node->right, index - w);
   }
}


int main(int argc, char const *argv[])
{
    //int arr[] = {6,4,8,2,7,3,1,69};
    //int arr[] = {22,33,44,55,66,99};
//    int arr[] = {44,23,63,17,33,51,74,8,20,48,58,71,46,72, 79, 83, 40, 2, 69, 7};
    int arr[] = {11, 3, 54,4, 55, 71, 43, 66, 22, 14, 12, 98, 39, 48, 1, 5, 81, 51, 93, 70};

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
    cout << endl;
    cout << "Range: {";
    T.RangeQuery(node, 30, 70);
    cout << "}" << endl;

    //tree select
    T.TreeSelect(node, 8);
    return 0;
}
