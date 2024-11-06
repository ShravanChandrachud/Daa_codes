#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

int main()
{
    int capacity, items;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> items;

    vector<int> price(items + 1); // Vector to store item prices
    vector<int> wt(items + 1);    // Vector to store item weights

    cout << "Enter the price of each item:\n";
    for (int i = 1; i <= items; i++)
    {
        cout << "Price of item " << i << ": ";
        cin >> price[i];
    }

    cout << "Enter the weight of each item:\n";
    for (int i = 1; i <= items; i++)
    {
        cout << "Weight of item " << i << ": ";
        cin >> wt[i];
    }

    vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= items; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (wt[i] <= j)
            {
                // Choose the maximum of either not taking the current item, or taking it and adding its value
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else
            {
                // If the item weight is more than the current capacity, don't take it
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}
