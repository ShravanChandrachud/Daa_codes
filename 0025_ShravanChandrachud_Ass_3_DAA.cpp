#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // Calculate value-to-weight ratio for each item
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second;

    // Return true if the first item has a higher ratio than the second
    return v1 > v2;
}

int main()
{
    int n;
    cout << "Enter value of N: ";
    // Input the number of items
    cin >> n;

    // Vector to store pairs of (value, weight) for each item
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        // Input value and weight for each item
        cout << "Input Value and Weight (in order):" << endl;
        cin >> a[i].first >> a[i].second;
    }

    int w; // Capacity of the knapsack

    cout << "Enter Capacity: ";
    cin >> w;

    // Sort items in descending order of their value-to-weight ratio
    sort(a.begin(), a.end(), compare);

    double ans = 0; // Variable to store the maximum value that can be achieved
    for (int i = 0; i < n; i++)
    {
        // If the current item's weight can fit in the remaining knapsack capacity
        if (w >= a[i].second)
        {
            ans += a[i].first; // Add the full value of the item
            w -= a[i].second;  // Decrease the knapsack capacity by the item's weight
            continue;          // Move to the next item
        }

        // If only part of the item can be taken due to limited capacity
        double vw = (double)a[i].first / a[i].second; // Value-to-weight ratio of the current item
        ans += vw * w;                                // Take as much as possible of the item's value
        w = 0;                                        // Knapsack is now full
        break;                                        // No more items can be added, so exit the loop
    }

    // Output the maximum value that can be achieved with the given capacity
    cout << "Maximum Value achieved is: " << ans << endl;
}
