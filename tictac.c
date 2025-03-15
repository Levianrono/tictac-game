#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void drawBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0; // Empty spot found

    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int makeMove(int choice) {
    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

int main() {
    int choice, moves = 0;
    
    while (1) {
        drawBoard();
        printf("Player %c, enter a number (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9 || !makeMove(choice)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        moves++;
        if (checkWin()) {
            drawBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isDraw()) {
            drawBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
