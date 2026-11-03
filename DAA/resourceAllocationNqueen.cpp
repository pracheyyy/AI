
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    // Check same row on left
    for(int j = 0; j < col; j++)
    {
        if(board[row][j] == 1)
            return false;
    }

    // Check upper diagonal
    int i = row;
    int j = col;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    // Check lower diagonal
    i = row;
    j = col;

    while(i < n && j >= 0)
    {
        if(board[i][j] == 1)
            return false;

        i++;
        j--;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n)
{
    // All queens are placed
    if(col >= n)
        return true;

    for(int i = 0; i < n; i++)
    {
        if(isSafe(board, i, col, n))
        {
            board[i][col] = 1;

            if(solveNQueens(board, col + 1, n))
                return true;

            // Backtracking
            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of tasks/resources: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if(solveNQueens(board, 0, n))
    {
        cout << "\nResource Allocation:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No conflict-free allocation exists";
    }

    return 0;
}
