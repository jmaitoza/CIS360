#include <iostream>
#include <vector>
using namespace std;

void floyd2(int n, int **W, int **D, int **P)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            P[i][j] = -1;
        }
    }

    D = W;
    //print out d
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void path (int q, int r, int **P)
{
    if (P[q][r] != -1)
    {
        path(q, P[q][r], P);
        cout << "v" << P[q][r] << " ";
        path(P[q][r], r, P);
    }

}

void addEdgeDir(int **W, int u, int v, int weight)
{
    W[u][v] = weight;
}
void addEdgeUnd(int **W, int u, int v, int weight)
{
    W[u][v] = weight;
    W[v][u] = weight;
}

int main()
{
    int n = 6;
    int **directedDense = new int *[n];
    for (int i = 0; i < n; i++) //initialize matrix
    {
        directedDense[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                directedDense[i][j] = 0;
            }
            else
            {
                directedDense[i][j] = 999;
            }
        }
    }
    int **undirectedSparse = new int *[n];
    for (int i = 0; i < n; i++) //initialize matrix
    {
        undirectedSparse[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                undirectedSparse[i][j] = 0;
            }
            else
            {
                undirectedSparse[i][j] = 999;
            }
        }
    }

    // add edges to directed graph
    addEdgeDir(directedDense, 0, 1, 5);
    addEdgeDir(directedDense, 1, 0, 7);

    addEdgeDir(directedDense, 1, 2, 1);

    addEdgeDir(directedDense, 2, 4, 1);
    addEdgeDir(directedDense, 4, 2, 3);

    addEdgeDir(directedDense, 4, 1, 1);
    addEdgeDir(directedDense, 4, 3, 1);
    addEdgeDir(directedDense, 4, 5, 6);

    addEdgeDir(directedDense, 0, 3, 11);

    addEdgeDir(directedDense, 3, 5, 20);

    // add edges to undirected graph
    addEdgeUnd(undirectedSparse, 0, 1, 5); // v1-v2 5
    addEdgeUnd(undirectedSparse, 1, 2, 11);// v2-v3 11
    addEdgeUnd(undirectedSparse, 2, 4, 4);// v3-v5 4
    addEdgeUnd(undirectedSparse, 4, 1, 7);// v5-v2 7
    addEdgeUnd(undirectedSparse, 4, 0, 3);// v5-v1 3
    addEdgeUnd(undirectedSparse, 3, 0, 1);// v4-v1 1
    addEdgeUnd(undirectedSparse, 3, 1, 5);// v4-v2 5
    addEdgeUnd(undirectedSparse, 3, 5, 4);// v4-v6 4
    addEdgeUnd(undirectedSparse, 5, 4, 4);// v6-v5 4
    addEdgeUnd(undirectedSparse, 5, 2, 13);// v6-v3 13


    //floyd2 directed graph
    int **D = new int *[n];
    for (int i = 0; i < n; i++)
    {
        D[i] = new int[n];
    }

    int **P = new int *[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = new int[n];
    }
    //directedDense
    floyd2(n, directedDense, D, P);
    path(0, 5, P);
    cout << endl;

    //undirectedSparse
    floyd2(n, undirectedSparse, D, P);
    path(0, 5, P);


    return 0;
}
