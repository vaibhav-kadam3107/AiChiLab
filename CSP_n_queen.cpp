#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int> &board, int row, int col, int n)
{
    
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row)
        {
            return false;
        }
    }

    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[j] == i)
        {
            return false;
        }
    }

    
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[j] == i)
        {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-queens problem
void solveNQueens(vector<int> &board, int col, int n, vector<vector<int>> &solutions)
{
    if (col == n)
    {
       
        solutions.push_back(board);
        return;
    }

 
    for (int i = 0; i < n; i++)
    {
        // Check if queen can be placed safely in this row
        if (isSafe(board, i, col, n))
        {
            board[col] = i; 

            // Recursively check if placing queen here leads to a solution
            solveNQueens(board, col + 1, n, solutions);

            // Backtrack
            board[col] = -1; // Remove queen
        }
    }
}


void printSolution(const vector<vector<int>> &solutions, int n)
{
    int numSolutions = solutions.size();
    cout << "Total Solutions: " << numSolutions << endl;
    for (int k = 0; k < numSolutions; k++)
    {
        cout << "Solution " << k + 1 << ":" << endl;
        const vector<int> &board = solutions[k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[j] == i)
                {
                    cout << " Q ";
                }
                else
                {
                    cout << " . ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;                
    vector<int> board(n, -1); 
    vector<vector<int>> solutions;

    solveNQueens(board, 0, n, solutions);

    if (!solutions.empty())
    {
        cout << "Solutions exist:" << endl;
        printSolution(solutions, n);
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}

/*Explanation:
Includes and Namespace:

#include <iostream>: Includes the standard input/output stream library.
#include <vector>: Includes the vector library.
using namespace std;: Allows use of standard library objects without the std:: prefix.
isSafe Function:

bool isSafe(const vector<int> &board, int row, int col, int n): Checks if placing a queen at position (row, col) is safe.
It checks the current column, the upper diagonal, and the lower diagonal for conflicts with existing queens.
If any queen is found in the same row or diagonals, it returns false. Otherwise, it returns true.
solveNQueens Function:

void solveNQueens(vector<int> &board, int col, int n, vector<vector<int>> &solutions): Recursively solves the N-queens problem.
If col equals n, it means all queens are placed correctly, and the current board configuration is added to solutions.
It iterates through each row in the current column to try placing a queen.
If placing a queen at (row, col) is safe, it places the queen and recursively attempts to place the rest.
It uses backtracking by removing the queen and trying the next possibility.
printSolution Function:

void printSolution(const vector<vector<int>> &solutions, int n): Prints all the solutions in a readable format.
It iterates through all solutions and prints each one in a grid format.
Queens are represented by " Q ", and empty spaces by " . ".
main Function:

int main(): The main function sets up the board and calls the function to solve the N-queens problem.
int n = 5;: Sets the size of the board to 5x5.
vector<int> board(n, -1);: Initializes the board with -1, indicating no queens are placed.
vector<vector<int>> solutions;: Initializes a vector to store all solutions.
solveNQueens(board, 0, n, solutions);: Calls the function to solve the N-queens problem starting from the first column.
If solutions are found, it prints them; otherwise, it indicates that no solution exists.
Summary:
This code solves the N-queens problem using a backtracking approach. It checks for safe positions to place queens on an n x n chessboard such that no two queens threaten each other. It stores all valid solutions and prints them in a human-readable format.*/