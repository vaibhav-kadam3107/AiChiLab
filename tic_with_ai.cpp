
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

struct Move
{
    int row, col;
};

void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " | ";
        }
        cout << endl
             << "-------------" << endl;
    }
}

bool isBoardFull(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkWinner(const vector<vector<char>> &board, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool isMoveValid(const vector<vector<char>> &board, int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY;
}

int evaluateBoard(const vector<vector<char>> &board)
{
    if (checkWinner(board, PLAYER_X))
    {
        return -1;
    }
    else if (checkWinner(board, PLAYER_O))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int minimax(vector<vector<char>> &board, int depth, bool isMaximizing)
{
    int score = evaluateBoard(board);

    if (score == 1 || score == -1)
    {
        return score;
    }

    if (isBoardFull(board))
    {
        return 0;
    }

    if (isMaximizing)
    {
        int maxScore = INT_MIN;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = PLAYER_O;
                    maxScore = max(maxScore, minimax(board, depth + 1, false));
                    board[i][j] = EMPTY;
                }
            }
        }
        return maxScore;
    }
    else
    {
        int minScore = INT_MAX;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = PLAYER_X;
                    minScore = min(minScore, minimax(board, depth + 1, true));
                    board[i][j] = EMPTY;
                }
            }
        }
        return minScore;
    }
}

Move findBestMove(vector<vector<char>> &board)
{
    int bestScore = INT_MIN;
    Move bestMove;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = PLAYER_O;
                int moveScore = minimax(board, 0, false);
                board[i][j] = EMPTY;

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    return bestMove;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, EMPTY));
    bool playerTurn = true;

    while (true)
    {
        printBoard(board);

        if (playerTurn)
        {
            int row, col;
            cout << "Enter your move (row and column, starting from 1): ";
            cin >> row >> col;
            row--; // Convert to zero-based index
            col--;

            if (isMoveValid(board, row, col))
            {
                board[row][col] = PLAYER_X;
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
                // continue;
                break;
            }
        }
        else
        {
            cout << "AI's move:" << endl;
            Move aiMove = findBestMove(board);
            board[aiMove.row][aiMove.col] = PLAYER_O;
        }
        if (checkWinner(board, PLAYER_X))
        {
            printBoard(board);
            cout << "Congratulations! You win!" << endl;
            break;
        }
        else if (checkWinner(board, PLAYER_O))
        {
            printBoard(board);
            cout << "AI wins! Better luck next time." << endl;
            break;
        }
        else if (isBoardFull(board))
        {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}

/*Initialization:

The program initializes the Tic-Tac-Toe board, constants for empty cells, and symbols for players (X and O).
Function Definitions:

printBoard: Prints the current state of the Tic-Tac-Toe board.
isBoardFull: Checks if the board is completely filled with player moves.
checkWinner: Checks if any player has won the game.
isMoveValid: Validates if a move is allowed at a given position.
evaluateBoard: Evaluates the current state of the board and assigns scores.
minimax: Implements the Minimax algorithm to determine the best move for the AI player.
findBestMove: Finds the best move for the AI player by invoking the minimax function.
Game Loop (main function):

The main function controls the flow of the game.
It alternates between the human player's turn and the AI opponent's turn until the game ends.
Working Example:

Demonstrates how the game progresses, with players taking turns and making moves until a win, loss, or draw condition is reached.
Attributes:

State Representation: The state of the game is represented by a 3x3 board, where each cell can be empty or filled with X or O.
Player Interaction: The game allows human players to make moves by inputting row and column indices. The AI opponent makes its moves based on the Minimax algorithm.
Outcome Determination: The game loop checks for win, loss, or draw conditions after each move and ends the game accordingly.
Optimization: The AI player uses the Minimax algorithm to make optimal moves, ensuring that it plays strategically to win or force a draw if victory is not possible.
Summary:
This Tic-Tac-Toe game implementation provides an interactive experience for human players and a challenging opponent in the form of an AI player. The AI player's moves are determined by the Minimax algorithm, ensuring strategic gameplay and allowing players to test their skills against an intelligent adversary.

Initialization:

The program initializes the Tic-Tac-Toe board, constants for empty cells, and symbols for players (X and O).
Function Definitions:

printBoard: Iterates through the board and prints each cell's content, separated by vertical lines, to represent the Tic-Tac-Toe grid.
isBoardFull: Checks if all cells on the board are filled with player moves. It iterates through the board and returns false if any cell is empty; otherwise, it returns true.
checkWinner: Checks if any player has won the game by examining the rows, columns, and diagonals for a winning combination of X's or O's. Returns true if a winning combination is found, otherwise false.
isMoveValid: Validates if a move is allowed at a given position. It checks if the specified row and column are within the bounds of the board and if the cell is empty.
evaluateBoard: Evaluates the current state of the board and assigns scores. It checks if either player has won or if the game is a draw, and assigns appropriate scores (-1 for X win, 1 for O win, 0 for draw).
minimax: Implements the Minimax algorithm to determine the best move for the AI player. It recursively evaluates all possible moves, alternating between maximizing and minimizing player, and returns the best score for the current board state.
findBestMove: Finds the best move for the AI player by invoking the minimax function. It iterates through all empty cells, makes a move, calculates the score using minimax, and selects the move with the highest score for the AI player.
Game Loop (main function):

The main function controls the flow of the game.
It alternates between the human player's turn and the AI opponent's turn until the game ends.
For each turn, it prints the current board state, prompts the human player to enter their move, validates the move, updates the board, and checks for a win, loss, or draw condition.
If the game ends, it prints the final board state and the outcome (win, loss, or draw).
Working Example:

Demonstrates how the game progresses, with players taking turns and making moves until a win, loss, or draw condition is reached.
It showcases the interaction between the human player and the AI opponent, with the AI making strategic moves based on the Minimax algorithm.
Summary:
This Tic-Tac-Toe game implementation provides an interactive experience for human players and a challenging opponent in the form of an AI player. The game flow and outcome are determined by the players' moves and the AI's strategic decision-making using the Minimax algorithm.*/