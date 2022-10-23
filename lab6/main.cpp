#include <iostream>
#include <random>
using namespace std;

struct heap
{
   int *S;
   int heapsize;
};

void siftdown (heap& H, int i)
{
    int parent, largerchild;
    int siftkey;
    bool spotfound;

    siftkey = H.S[i];
    parent = i;
    spotfound = false;

    while (2*parent <= H.heapsize && !spotfound)
    {
        if (2*parent < H.heapsize && H.S[2*parent] < H.S[2*parent+1])
            largerchild = 2*parent+1; //index of right child is 1 more than twice that of parent
        else
            largerchild = 2*parent; //index of left child is twice that of parent

        if (siftkey < H.S[largerchild])
        {
            H.S[parent] = H.S[largerchild];
            parent = largerchild;
        }
        else
            spotfound = true;
    }
    H.S[parent] = siftkey;
}

void makeheap (int n, heap &H)
{
    int i;
    H.heapsize = n;
    for (i = (n/2); i >= 1; i--)
        siftdown(H, i);
}

heap heapsort (int n, heap &H)
{
    int i;
    int temp;
    makeheap(n, H);
    for (i = n; i >= 2; i--)
    {
        temp = H.S[1]; // set temp to root element
        H.S[1] = H.S[i]; //move last element to root
        H.S[i] = temp; //removekeys method
        H.heapsize--; //delete bottom node
        siftdown(H, 1); //restore heap property
    }
    return H;
}

void printdepth(int n, heap &H)
{
    cout << "heap structure by depth:" << endl;
    for (int i = 1; i <= n; i++)
        cout << "d=" << (int)log2(i) << " " << H.S[i] << endl; // log2(i) is the depth of node i
}


int main() {
    int S[501];
    int n = 500; //change n to get different test cases
    // C++ way to initialize random number generator
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 999); // range is [1, 999]

    // initialize array with n distinct random numbers
    cout << "Unsorted array: " << endl;
    for (int i = 1; i <= n; i++) {
        S[i] = dist(mt);
        cout << S[i] << " " << endl;
    }

    heap H{}; //declare heap
    H.S = S; //assign array to heap
    cout << endl;
    heapsort(n, H);
    printdepth(n, H);

    return 0;
}
