#include <iostream>
using namespace std;

//int n; // number of items
//int W; // total allowed weight


void DP01Knapsack(int n, int W, int Profits[n], int Weights[n])
{
    int includedProfits = 0;
    int omittedProfits = 0;
    //initialization
    // P (n+1) x (W+1) matrix
    int P[n+1][W+1];

    for (int w = 0 ; w <= W ; w++)
        P[0][w] = 0;
    for (int i = 0 ; i <= n ; i++)
        P[i][0] = 0;

    // Profit calculation
    for (int i = 0; i < n; i++)
    {
        for (int w = 0; w < W; w++)
        {
            if (Weights[i] <= w)
            {
                includedProfits = Profits[i] + P[i][w-Weights[i]];
                omittedProfits = P[i][w];
                P[i+1][w] = max(includedProfits, omittedProfits);
            }
            else
                P[i+1][w] = P[i][w];
        }
    }
    cout << "Included profit: " << includedProfits << endl;
    cout << "Omitted profit: " << omittedProfits << endl;
}

void Greedy01Knapsack(int n, int W, int Profits[n], int Weights[n])
{
    int includedProfits = 0;
    int omittedProfits = 0;
    int PdivW[n];
    int temp = 0;
    // init P
    int P[n+1][W+1];

    for (int w = 0 ; w <= W ; w++)
        P[0][w] = 0;
    for (int i = 0 ; i <= n ; i++)
        P[i][0] = 0;

    for (int i = 0; i < n; i++)
    {
        PdivW[i] = Profits[i] / Weights[i];
        cout << "PdivW[" << i << "]: " << PdivW[i] << endl;
    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << PdivW[i] << " ";
//    }
    //sort the items by their profit/weight ratio with largest first
    sort(PdivW, PdivW + n, greater<>());

    for(int i=0; i<n; i++)
    {
        cout << "SortedPdivW[" << i << "]: "<< PdivW[i] << endl;
    }

    //for each item, if it fits, add it to the knapsack
    for (int i = 0; i < n; i++)
    {
        if (PdivW[i] <= W)
        {

        }
    }
    cout << "Included profit: " << includedProfits << endl;
    cout << "Omitted profit: " << omittedProfits << endl;

}



int main()
{
    //dp01knapsack
    int n = 3;
    int W = 8;
    // Profits: list of n item profits (randomly generated)
    int Profits[] = {20, 30, 35};
    // Weights: list of n item weights (randomly generated)
    int Weights[] {7, 3, 1};

    // test case

//    for (int i = 0; i < n; i++)
//    {
//        Profits[i] = rand() % 100 +1; //$1 to $100
//        Weights[i] = rand() % 10 +1; //1 to 10 lbs
//    }
    //print out profits and weights
    cout << "DP01Knapsack" << endl;
    cout << "Profits: ";
    for (int i = 0; i < n; i++)
    {
        cout << Profits[i] << " ";
    }
    cout << endl;
    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cout << Weights[i] << " ";
    }
    cout << endl;

//    DP01Knapsack(n, W, Profits, Weights);
    Greedy01Knapsack(n, W, Profits, Weights);


    return 0;
}
