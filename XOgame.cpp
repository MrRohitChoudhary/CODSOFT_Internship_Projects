#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool isMoveValid(int move) {
    if (move < 1 || move > 9) {
        return false;
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    return true;
}

bool checkWin() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int move;
    bool gameOn = true;

    while (gameOn) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (isMoveValid(move)) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOn = false;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a Tie!" << endl;
                gameOn = false;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
            for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
            board[i][j] = (char)('1' + i * 3 + j);
            }
        }
        currentPlayer = 'X';
        gameOn = true;
    }

    return 0;
}

