#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function for LCS using Divide and Conquer

int lcs_divide_and_conquer(const string &X, const string &Y, int m, int n)
{
    // Base case: if either string is empty
    if (m == 0 || n == 0)
    {
        return 0;
    }

    // If last characters match
    if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs_divide_and_conquer(X, Y, m - 1, n - 1);
    }
    else
    {
        // If last characters do not match
        return max(lcs_divide_and_conquer(X, Y, m, n - 1), lcs_divide_and_conquer(X, Y, m - 1, n));
    }
}

// Function for LCS using Dynamic Programming
int lcs_dynamic_programming(const string &X, const string &Y)
{
    int m = X.length();
    int n = Y.length();

    // Create a DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of LCS will be in the last cell
    return dp[m][n];
}

// Function to display results
// Function to display results based on user's choice of algorithm
void displayResults(const string &X, const string &Y, int choice)
{
    int result;
    if (choice == 1)
    {
        result = lcs_divide_and_conquer(X, Y, X.length(), Y.length());
        cout << "Length of LCS (Divide and Conquer) is: " << result << endl;
    }
    else if (choice == 2)
    {
        result = lcs_dynamic_programming(X, Y);
        cout << "Length of LCS (Dynamic Programming) is: " << result << endl;
    }
    else
    {
        cout << "Invalid choice! Please select 1 or 2." << endl;
    }
}
// Main function
int main()
{
    string X, Y;
    int choice;
    // Get custom input strings
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;
    // Get user's choice for algorithm
    cout << "\nChoose the algorithm to calculate LCS:" << endl;
    cout << "1. Divide and Conquer" << endl;
    cout << "2. Dynamic Programming" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    // Display the results based on selected algorithm
    displayResults(X, Y, choice);
    return 0;
}
