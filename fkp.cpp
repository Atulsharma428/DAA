#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sortKnapsack(vector<int> &weight, vector<int> &cost)
{
    vector<int> divide;
    for (int i = 0; i < weight.size(); i++)
    {
        divide.push_back(cost[i] / weight[i]);
    }

    for (int i = 0; i < divide.size() - 1; i++)
    {
        for (int j = 0; j < divide.size() - i - 1; j++)
        {
            if (divide[j] < divide[j + 1])
            {
                swap(divide[j], divide[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(cost[j], cost[j + 1]);
            }
        }
    }
}

int knapsack(vector<int> &weight, vector<int> &cost, int n, int k)
{
    int kWeight = 0, c = 0;
    vector<float> x;

    for (int i = 0; i < n; i++)
    {
        x.push_back(0);
    }

    int i = 0;
    while (kWeight + weight[i] <= k)
    {
        x[i] = 1;
        kWeight += weight[i];
        i += 1;
    }

    x[i] = (float)(k - kWeight) / weight[i];

    for (int i = 0; i < n; i++)
    {
        c = c + (x[i] * cost[i]);
    }

    return c;
}

int main()
{
    vector<int> weight, cost;
    int i, k, size, a;
    cout << "Enter size of W and V: ";
    cin >> size;
    for (i = 0; i < size; i++)
    {
        cout << "W[" << i << "]: ";
        cin >> a;
        weight.push_back(a);
    }
    cout << endl;

    for (i = 0; i < size; i++)
    {
        cout << "V[" << i << "]: ";
        cin >> a;
        cost.push_back(a);
    }

    cout << "\nEnter k: ";
    cin >> k;
    sortKnapsack(weight, cost);

    int ans = knapsack(weight, cost, size, k);

    cout << ans << endl;
    return 0;
}