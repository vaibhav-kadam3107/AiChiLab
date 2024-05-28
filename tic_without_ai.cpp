#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char EMPTY = ' ';

void printBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "---------" << endl;
        }
    }
}

bool checkWin(const vector<vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void convertMove(int move, int &row, int &col)
{
    move--;
    row = move / 3;
    col = move % 3;
}

bool isMoveValid(const vector<vector<char>> &board, int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY;
}

void tictactoe()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'O';

    while (true)
    {
        printBoard(board);

        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            break;
        }

        int row, col;
        convertMove(move, row, col);

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer))
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    tictactoe();
    return 0;
}

/*
Print Board Function (printBoard):

This function is responsible for printing the current state of the Tic Tac Toe board.
It iterates over each cell in the board and prints the content. Vertical lines are used to separate cells, and horizontal lines are used to separate rows.
Check Win Function (checkWin):

This function checks if a player has won the game.
It examines each row, column, and diagonal of the board to see if all cells contain the same player's symbol ('X' or 'O').
If a winning combination is found, the function returns true; otherwise, it returns false.
Is Board Full Function (isBoardFull):

This function checks if the Tic Tac Toe board is completely filled with player moves.
It iterates over each cell of the board and checks if any cell is empty.
If all cells are filled, the function returns true; otherwise, it returns false.
Convert Move Function (convertMove):

This function converts a player's move from a single integer (1-9) to a row and column coordinate on the board.
It subtracts 1 from the move to convert it to a zero-based index and calculates the row and column accordingly.
Is Move Valid Function (isMoveValid):

This function checks if a player's move is valid.
It verifies if the specified row and column are within the bounds of the board and if the cell is empty.
If the move is valid, the function returns true; otherwise, it returns false.
Tic Tac Toe Function (tictactoe):

This is the main game loop function.
It initializes the board and starts the game loop, where players take turns making moves until a win, loss, or draw condition is reached.
Within each turn, it prints the current board state, prompts the player for their move, validates the move, updates the board, and checks for a win or draw condition.
If the game ends, it prints the final board state and outcome (win or draw).
Main Function:

This is the entry point of the program.
It displays a welcome message and calls the tictactoe function to start the game.
Summary:
This code implements a simple command-line Tic Tac Toe game where two players (X and O) take turns making moves until one player wins or the game ends in a draw. The game state is displayed after each move, and players are prompted to enter their moves using numbers corresponding to the board cells.*/