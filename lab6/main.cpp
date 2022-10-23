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


int main() {
    int S[100];
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 500); // range is [1, 100]

    // initialize array with 100 random numbers
    for (int i = 1; i <= 8; i++) {
        S[i] = dist(mt);
        //cout << S[i] << " " << endl;
    }

    heap H{}; //declare heap
    H.S = S; //assign array to heap
    makeheap(8, H); //make heap

    //print heap and the depth of each node
    for (int i = 1; i <= 8; i++) {
        cout << "d=" << (int)log2(i) << " " << H.S[i] << endl;
    }



//    for (int i = 1; i <= 8; i++) {
//        cout << H.S[i] << " " << endl;
//    }


    return 0;
}
