#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>> &arr, int x, int y, int n)
{
    // Check column for previous rows
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    // Check upper left diagonal
    for (int row = x, col = y; row >= 0 && col >= 0; row--, col--)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }

    // Check upper right diagonal
    for (int row = x, col = y; row >= 0 && col < n; row--, col++)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
    }

    return true;
}

void printBoard(const vector<vector<int>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                cout << "[Q]";
            else
                cout << "[]";
        }
        cout << endl;
    }
    cout << endl;
}

void nQueen(vector<vector<int>> &arr, int x, int n)
{
    if (x == n)
    {
        printBoard(arr, n);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;       // Place queen
            nQueen(arr, x + 1, n); // Recur to place the next queen
            arr[x][col] = 0;       // Backtrack
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0)); // Initialize the board with 0s

    nQueen(arr, 0, n);

    cout << "--------All possible solutions--------" << endl;

    return 0;
}

/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/
