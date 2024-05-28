#include <bits/stdc++.h>
using namespace std;
#include <iostream>

const int N = 8;

int calcEvaluationFunction(int (&board)[N])
{
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = i + 1; j < 8; ++j)
        {
            if (board[i] == board[j])
                ++cnt;
            else if (abs(i - j) == abs(board[i] - board[j]))
                ++cnt;
        }
    }
    return 28 - cnt;
}

void printBoard(int (&board)[N])
{
    int grid[10][10];
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < 8; ++i)
        grid[board[i]][i] = 1;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return;
}

void copyBoard(int (&board1)[N], int (&board2)[N])
{
    for (int i = 0; i < 8; ++i)
        board1[i] = board2[i];
}

bool hillClimbing(int (&board)[N])
{
    int bestBoard[N], bestValue, boardValue;
    copyBoard(bestBoard, board);

    int cnt = 0;
    while (1)
    {
        int currBoard[N], currValue;
        copyBoard(currBoard, board);
        boardValue = bestValue = calcEvaluationFunction(board);

        if (bestValue == 28)
        {
            cout << "Reached Global Maxima after " << cnt << " moves" << endl;
            printBoard(bestBoard);
            return 1;
        }

        ++cnt;
        for (int i = 0; i < 8; ++i)
        {
            int temp = currBoard[i];
            for (int j = 0; j < 8; ++j)
            {
                if (j == board[i])
                    continue;
                currBoard[i] = j;
                currValue = calcEvaluationFunction(currBoard);
                if (currValue > bestValue)
                {
                    bestValue = currValue;
                    copyBoard(bestBoard, currBoard);
                }
            }
            currBoard[i] = temp;
        }
        if (bestValue <= boardValue)
        {
            cout << "Stucked in Local Maxima after " << cnt << " moves" << endl;
            printBoard(bestBoard);
            return 0;
        }
        copyBoard(board, bestBoard);
    }
}

int main()
{
    //~ freopen("output.txt", "w", stdout);
    srand(time(NULL));
    bool success = 0;
    int cnt = 1, board[N];
    while (1)
    {
        for (int i = 0; i < 8; ++i)
            board[i] = rand() % 8;

        cout << "======================== Iteration : " << cnt << endl;
        cout << "Initial Board" << endl;
        printBoard(board);
        success = hillClimbing(board);
        ++cnt;

        if (success)
            break;
    }

    return 0;
}

/*Certainly! Let's break down the code further, focusing on its key attributes and components:

### 1. Evaluation Function (`calcEvaluationFunction`):
- **Purpose**: Evaluates the current board configuration based on the number of attacking queen pairs.
- **Attributes**:
  - `board[N]`: An array representing the current board configuration with queens placed on different rows in each column.
  - `cnt`: Counter variable to keep track of the number of attacking queen pairs.
- **Algorithm**:
  - Iterates through each pair of queens on the board.
  - Checks if the queens are in the same row or diagonally attacking each other.
  - Increments the `cnt` variable for each attacking pair.
  - Calculates the heuristic value as `28 - cnt`, where `28` represents the total number of non-attacking queen pairs.

### 2. Print Board Function (`printBoard`):
- **Purpose**: Visualizes the current board configuration.
- **Attributes**:
  - `board[N]`: The current board configuration.
  - `grid[10][10]`: A 2D grid representation of the chessboard, with queens represented as `1` and empty cells as `0`.
- **Algorithm**:
  - Initializes the `grid` with zeros.
  - Sets `1` at the positions corresponding to the queens' locations on the board.
  - Prints the grid to the console, representing the queens' positions and empty cells.

### 3. Copy Board Function (`copyBoard`):
- **Purpose**: Copies the contents of one board configuration to another.
- **Attributes**:
  - `board1[N]`: Destination board to copy to.
  - `board2[N]`: Source board to copy from.
- **Algorithm**:
  - Iterates through each column and copies the corresponding queen's row from `board2` to `board1`.

### 4. Hill Climbing Algorithm (`hillClimbing`):
- **Purpose**: Implements the Hill Climbing algorithm to solve the 8-queens problem.
- **Attributes**:
  - `board[N]`: The current board configuration.
  - `bestBoard[N]`: The best board configuration found so far.
  - `boardValue`: The evaluation value of the current board.
  - `bestValue`: The evaluation value of the best board configuration.
  - `cnt`: Counter variable to track the number of iterations.
- **Algorithm**:
  - Initializes `bestBoard` with the current board configuration.
  - Enters a loop until a solution is found or a termination condition is met.
  - Evaluates neighboring board configurations by moving each queen to a different row in its column.
  - Selects the configuration with the highest evaluation value as the new best board configuration.
  - If a global maximum (no attacking pairs) is reached, terminates the search and returns `true`.
  - If stuck in a local maximum, terminates the search and returns `false`.

### 5. Main Function:
- **Purpose**: Executes the search process and prints the results.
- **Attributes**:
  - `board[N]`: The initial board configuration.
  - `success`: Boolean variable indicating whether a solution is found.
  - `cnt`: Counter variable to track the number of iterations.
- **Algorithm**:
  - Initializes a random initial board configuration.
  - Enters a loop to repeatedly apply the Hill Climbing algorithm until a solution is found.
  - Prints the initial board configuration and the iteration number.
  - Indicates whether the search reaches a global maximum or gets stuck in a local maximum.

### Overall:
The code efficiently solves the 8-queens problem using the Hill Climbing algorithm by iteratively improving the board configuration until a solution is found or until it reaches the maximum number of iterations. It implements key functions and algorithms with appropriate attributes to manage the search process effectively.*/
