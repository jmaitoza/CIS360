#include <iostream>
#include <vector>

using namespace std;

class UnionSet
{
    int *parent;
    int *size;
    int depth;
//    int depthCount;

public:

    void makeSet(int n);
    int Find2(int e);
    int Find(int e);
    void Union(int A, int B);
    void Union2(int A, int B);
    void printSet(UnionSet &s, int n);
    void printSet2(UnionSet &s, int n);
    int getDepth(int e);

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

int UnionSet::Find2(int e) {
//    depthCount = 0;
    int root = e;
    while (parent[root] != root)
    {
        root = parent[root];
    }
//    else
//    {
//        return parent[e] = Find2(parent[e]); //path compression
//    }
    return parent[root];
}

int UnionSet::getDepth(int e) {
    int depthcount = 0;
    int current = e;
    while (parent[current] != current)
    {
        current = parent[current];
        depthcount++;
    }
    return depthcount;
}

void UnionSet::Union(int A, int B)
{
    int x = Find(A);
    int y = Find(B);

    if (size[x] < size[y]) //keep this one for heuristics
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

void UnionSet::Union2(int A, int B)
{
    int x = Find2(A);
    int y = Find2(B);


        parent[y] = x;
        size[x] += size[y];
        cout << "X:" << x << "Y:" << y << endl;
}

void UnionSet::printSet(UnionSet &s, int n) {
    // print format: node (root, depth)
    cout << n << " (" << s.Find(n) << ", " << getDepth(n) << ")" << endl;
}

void UnionSet::printSet2(UnionSet &s, int n)
{
    // print format: node (root, depth)
    cout << n << " (" << s.Find2(n) << ", " << getDepth(n) << ")" << endl;
}

int UnionSet::Find(int e)
{
    int root = e;
    while (parent[root] != root)
    {
        root = parent[root];
    }

    int z = e;
    int w = 0;
    while(parent[z] != z) //path compression
    {
        w = z;
        z = parent[z];
        parent[w] = root;
    }
    return parent[root];
}

int main()
{
    UnionSet asshole{};
    UnionSet set2{};
    asshole.makeSet(50);
    cout << "Version 1" << endl;
    for (int i = 0; i < 45; i++)
    {
        asshole.Union(i, i + 5);
    }
    for (int i = 0; i < 50; i++)
    {
        asshole.printSet(asshole, i);
    }

    set2.makeSet(50);
    cout << "Version 2" << endl;
    for (int i = 0; i < 50; i++)
    {
        set2.Union2(i, i+5);
    }
    for (int i = 0; i < 50; i++)
    {
        set2.printSet2(set2, i);
    }

    return 0;
}
