/* Step 1: Implement tree based union find data structure with 3 methods:
    makeSet(e): Create a set containing the element e and name it e
    union(A,B): Update A and B to create A U B
    find(e): Return the name of the set containing e
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class UnionFindSet
{ 
    struct Node
    {
        int data;
        Node* parent;
        int size;
        //int depth;
    };
public: 
    void makeSet(int e);
    void Union(int A, int B);
    int Find(int e);
    
};

void UnionFindSet::makeSet(int e)
{
    Node* node = new Node;
    node->data = e;
    node->parent = node;
    node->size = 1;
}

int UnionFindSet::Find(int e)
{
    Node *temp = new Node;
    temp->data = e;
    int depth = 0;

    //base case
    if (temp->parent == temp)
    {
        cout << endl;
        cout << "Depth of " << e << " is " << depth << " ";
        return temp->data;
    }
    // TODO: Implement depth using a vector
    depth++;
    return Find(temp->parent->data);
    
    // else
    // {
    //     // recursive case
    //     return Find(temp->parent->data);
    //     depth++;
    // } 
}

void UnionFindSet::Union(int A, int B)
{
    Node *tempA = new Node;
    Node *tempB = new Node;
    tempA->data = A;
    tempB->data = B;
    if (tempA->size < tempB->size)
    {
        tempA->parent = tempB;
        tempB->size = tempB->size + tempA->size;
    }
    else
    {
        tempB->parent = tempA;
        tempA->size = tempA->size + tempB->size;
    }
}

int main(int argc, char const *argv[])
{
    UnionFindSet set;
    for (int i = 0; i < 49; i++)
    {
        set.makeSet(i);
    }
    for (int i = 0; i < 49; i++)
    {
        set.Union(set.Find(i), set.Find(i+5));
    }


    return 0;
}
