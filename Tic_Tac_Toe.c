#include <stdio.h>

// Function to display the Tic Tac Toe board Game
void DisplayBoard(char board[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            printf(" %c ", board[x][z]);
            if (z < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (x < 2) {
            printf("---+---+---\n");
        }
    }
}

// Function to check if the player has won or not!
int CheckWin(char board[3][3], char player) {
    for (int x = 0; x < 3; x++) {
        if (board[x][0] == player && board[x][1] == player && board[x][2] == player) {
            return 1; // Row win 
        }
        if (board[0][x] == player && board[1][x] == player && board[2][x] == player) {
            return 1; // Column win
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Reverse diagonal win
    }

    return 0; // No win yet
}

// Function to check if the board is full or not!
int IsBoardFull(char board[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            if (board[x][z] == ' ') {
                return 0; // The board is not full yet
            }
        }
    }
    return 1; // The board is full
}

int main() {
    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    int row, col;
    char player = 'X';

    printf("Let's play Tic-Tac-Toe Game\n");
    DisplayBoard(board);

    while (1) {
        // Input player's move
        printf("Player %c, Enter your move! (row [1-3] and column [1-3]): ", player);
        scanf("%d %d", &row, &col);

        // Convert to zero-based index
        row--;
        col--;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Display the updated board
        DisplayBoard(board);

        // Check if the current player has won
        if (CheckWin(board, player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        // Check if the board is full (draw)
        if (IsBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        // Switch to the other player for the next turn for playing
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}