
#include <iostream>
#include <vector>
using namespace std;

int count = 0;

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

void printBoard(vector<vector<int>>& board, int n)
{
    count++;

    cout << "\nSolution " << count << ":\n";

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

void solveNQueens(vector<vector<int>>& board, int col, int n)
{
    // All queens placed
    if(col >= n)
    {
        printBoard(board, n);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isSafe(board, i, col, n))
        {
            board[i][col] = 1;

            solveNQueens(board, col + 1, n);

            // Backtracking
            board[i][col] = 0;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    if(count == 0)
        cout << "No solution exists";

    cout << "\nTotal solutions: " << count;

    return 0;
}
