#include <iostream>
#include <stack>
using namespace std;

// binary tree node data structure
struct BinaryTreeNode
{
    char data;
    BinaryTreeNode *left;
    BinaryTreeNode *right; 
};

//implement post order traversal and print the data
void postOrderTraverse(BinaryTreeNode *root)
{
    // check if inputted expression is empty, if so return
    if (root == NULL)
        return;
    stack<BinaryTreeNode *> s;
    BinaryTreeNode *prev = NULL;
    do
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        while (root == NULL && !s.empty())
        {
            root = s.top();
            if (root->right == NULL || root->right == prev)
            {
                cout << root->data << " ";
                s.pop();
                prev = root;
                root = NULL;
            }
            else
                root = root->right;
        }
    } while (!s.empty());
}

//implement pre order traversal and print the data
void preOrderTraverse(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    stack<BinaryTreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        BinaryTreeNode *node = s.top();
        cout << node->data << " ";
        s.pop();
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

//implement in order traversal and print the data
void inOrderTraverse(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    stack<BinaryTreeNode *> s;
    BinaryTreeNode *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main(int argc, char const *argv[])
{
    char pfixExp[] = {'2', '3', '4', '*', '+', '5', '6', '*', '+'};  
    //create an empty stack
    stack<BinaryTreeNode*> expTree; //stack
    
    // read in each character of the postfix expression
    for (int i = 0; i < sizeof(pfixExp); ++i)
    {
        // if the character is an operand
        if (pfixExp[i] >= '0' && pfixExp[i] <= '9')
        {
            // create a one node tree
            BinaryTreeNode *node = new BinaryTreeNode;
            node->data = pfixExp[i];
            node->left = NULL;
            node->right = NULL;
            // push the node onto the stack
            expTree.push(node);
        }
        // if the character is an operator
        else
        {
            // create a new node
            BinaryTreeNode *node = new BinaryTreeNode;
            node->data = pfixExp[i];
            // pop the top two nodes from the stack
            node->right = expTree.top(); //T1 (popped first)
            expTree.pop();
            node->left = expTree.top(); //T2 (popped second)
            expTree.pop();
            // push the new node onto the stack
            expTree.push(node);
        }
    }
    postOrderTraverse(expTree.top());
    cout << endl;
    preOrderTraverse(expTree.top());
    cout << endl;
    inOrderTraverse(expTree.top());
    cout << endl;
    
    return 0;
}
