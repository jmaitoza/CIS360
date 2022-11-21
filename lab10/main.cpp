#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

bool ratioCompare(pair <int, int> a, pair <int, int> b) {
    return a.first > b.first;
}




void DP01Knapsack(const int n, const int W, vector<int> profits, vector<int> weights)
{
    int includedProfits = 0;
    int omittedProfits = 0;

    //initialization
    // P (n+1) x (W+1) matrix
    vector<vector<int>> P(n+1, vector<int>(W+1));
    for (int w = 0; w <= W; w++)
        P[0][w] = 0;
    for (int i = 1; i <= n; i++)
        P[i][0] = 0;

    // Profit calculation
    for (int i = 1; i < n; i++)
    {
        for (int w = 1; w < W; w++)
        {
            if (weights[i] <= w)
            {
                includedProfits = profits[i] + P[i-1][w-weights[i]];
                omittedProfits = P[i-1][w];
                P[i][w] = max(includedProfits, omittedProfits);
            }
            else
                P[i][w] = P[i-1][w];
        }
    }

    cout << "Included profit: " << includedProfits << endl;
    cout << "Omitted profit: " << omittedProfits << endl;
}

void greedy01Knapsack(int n, int W, vector<int> profits, vector<int> weights)
{
    int includedProfits = 0;
    int omittedProfits = 0;

    vector<pair<int, int>> ratio(n, make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        ratio[i] = make_pair((profits[i]/weights[i]), i);
    }

    //sort the ratio vector by profit/weight
    sort(ratio.begin(), ratio.end(), ratioCompare);

    for (int i = 0; i < n; i++)
    {
        if (weights[ratio[i].second] <= W)
        {
            includedProfits += profits[ratio[i].second];
            W -= weights[ratio[i].second];
        }
        else
        {
            omittedProfits += profits[ratio[i].second];
        }
    }

    cout << "Included profit: " << includedProfits << endl;
    cout << "Omitted profit: " << omittedProfits << endl;
}

void fracKnapsack(int n, int W, vector<int> profits, vector<int> weights)
{
    int includedProfits = 0;
    int omittedProfits = 0;

    vector<pair<float, int>> ratio(n, make_pair(0.0, 0)); // to store items by profit/weight
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
        else //item does not fit in bag so take fraction
        {
            int fraction = profits[v] * (float(W)/float(weights[v]));
            includedProfits += fraction;
            W = 0;
            omittedProfits += profits[v] - fraction;
        }
    }
    cout << "Included profit: " << includedProfits << endl;
    cout << "Omitted profit: " << omittedProfits << endl;
}



int main()
{
    //dp01knapsack
    srand((unsigned)time(nullptr));
    int n = 100;
    int W = 50;
    // Profits: list of n item testprofits (randomly generated)
    int Profits[] = {20, 30, 35};
//    // Weights: list of n item testweights (randomly generated)
    int Weights[] = {7, 3, 1};
    //test case
    vector <int> testprofits = {20, 30, 35};
    vector <int> testweights = {7, 3, 1};

    vector<int> profits;
    vector<int> weights;

    //initialize vectors with random integers
    for (int i = 0; i < n; i++)
    {
        profits.push_back(rand() % 100 + 1);
        weights.push_back(rand() % 100 +1);
    }

    //print out testprofits and testweights
    cout << "DP01Knapsack" << endl;
    cout << "Profits: ";
    for (int i = 0; i < n; i++)
    {
        cout << profits[i] << " ";
    }
    cout << endl;
    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cout << weights[i] << " ";
    }
    cout << endl;
    DP01Knapsack(n, W, profits, weights);
    cout<< endl;

    cout << "Greedy01Knapsack" << endl;
    cout << "Profits: ";
    for (int i = 0; i < n; i++)
    {
        cout << profits[i] << " ";
    }
    cout << endl;
    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cout << weights[i] << " ";
    }
    cout << endl;
    greedy01Knapsack(n, W, profits, weights);
    cout << endl;

    //fracKnapsack
    cout << "FracKnapsack" << endl;
    cout << "Profits: ";
    for (int i = 0; i <n; i++)
    {
        cout << profits[i] << " ";
    }
    cout << endl;
    cout << "Weights: ";
    for (int i = 0; i < n; i++)
    {
        cout << weights[i] << " ";
    }
    cout << endl;
    fracKnapsack(n, W, profits, weights);


    return 0;
}
