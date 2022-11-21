#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool ratioCompare(pair <int, int> a, pair <int, int> b) {
    return a.first > b.first;
}


//void DP01Knapsack(int n, int W, int Profits[n], int Weights[n])
//{
//    int includedProfits = 0;
//    int omittedProfits = 0;
//    //initialization
//    // P (n+1) x (W+1) matrix
//    int P[n+1][W+1];
//
//    for (int w = 0 ; w <= W ; w++)
//        P[0][w] = 0;
//    for (int i = 0 ; i <= n ; i++)
//        P[i][0] = 0;
//
//    // Profit calculation
//    for (int i = 0; i < n; i++)
//    {
//        for (int w = 0; w < W; w++)
//        {
//            if (Weights[i] <= w)
//            {
//                includedProfits = Profits[i] + P[i][w-Weights[i]];
//                omittedProfits = P[i][w];
//                P[i+1][w] = max(includedProfits, omittedProfits);
//            }
//            else
//                P[i+1][w] = P[i][w];
//        }
//    }
//    cout << "Included profit: " << includedProfits << endl;
//    cout << "Omitted profit: " << omittedProfits << endl;
//}

void fracKnapsack(int n, int W, vector<int> profits, vector<int> weights)
{
    int includedProfits = 0;
    int omittedProfits = 0;

    vector<pair<int, int>> ratio(n, make_pair(0, 0)); // to store items by profit/weight
    for (int i = 0; i < n; i++)
    {
        ratio[i] = make_pair((profits[i]/weights[i]), i);
    }

    //sort items by profit/weight
    sort(ratio.begin(), ratio.end(), ratioCompare);

    for (int i = 0; i < n; i++)
    {
        int v = ratio[i].second;

        if (weights[v] <= W) // item does fit
        {
            includedProfits += profits[v];
            W -= weights[v];
        }
        else //item does not fit in bag
        {
            omittedProfits += profits[v] * (W/weights[v]);
            W = 0;
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
//    // Weights: list of n item weights (randomly generated)
    int Weights[] {7, 3, 1};
    vector <int> profits = {20, 30, 35};
    vector <int> weights = {7, 3, 1};
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
    //Greedy01Knapsack(n, W, Profits, Weights);

    //fracKnapsack
    cout << "FracKnapsack" << endl;
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
    fracKnapsack(n, W, profits, weights);


    return 0;
}
