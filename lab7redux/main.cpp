#include <iostream>
#include <vector>

using namespace std;

class UnionSet
{
    int *parent;
    int *size;
    int depth;
    int depthCount;
public:

public:

    void makeSet(int n);
    int Find(int e);
    void Union(int A, int B);

    void printSet(UnionSet &s, int n);

//    int depthCount;
};

void UnionSet::makeSet(int n) {
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int UnionSet::Find(int e) {
//    depthCount = 0;
    if (e == parent[e])
    {
        return e;
    }
    else
    {
        depthCount++;
        return parent[e] = Find(parent[e]); //path compression
    }
}

void UnionSet::Union(int A, int B)
{
    int x = Find(A);
    int y = Find(B);

    if (size[x] < size[y])
    {
        parent[x] = y;
        size[y] += size[x];
    }
    else
    {
        parent[y] = x;
        size[x] += size[y];
    }
}

//void UnionSet::printSet(UnionSet &s, int n) {
//    // print format: node (root, depth)
//    cout << n << " (" << s.Find(n) << ", " << depthCount << ")" << endl;
//}

int main()
{
    UnionSet asshole{};
    asshole.makeSet(50);
    cout << "cringe" << endl;
    for (int i = 0; i < 50; i++)
    {
        asshole.Union(i, i + 5);
//        asshole.printSet(asshole, i);
//        asshole.depthCount = 0;
    }

    return 0;
}
