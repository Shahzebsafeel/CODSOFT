#include <iostream>
#include <vector>

using namespace std;

#define YOU 'X'
#define COMPUTER_PLAYER 'O'
#define EMPTY_CELL '-'

struct Move {
    int row, col;
};

class TICTACAI {
private:
    char board[3][3];
public:
    TICTACAI() {
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = EMPTY_CELL;
            }
        }
    }

    bool isMoveValid(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY_CELL);
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == EMPTY_CELL)
                    return false;
            }
        }
        return true;
    }

    char checkWinner() {
        
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY_CELL)
                return board[i][0];
        }

        
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY_CELL)
                return board[0][i];
        }

        
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY_CELL)
            return board[0][0];

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY_CELL)
            return board[0][2];

       
        return EMPTY_CELL;
    }

    void printBoard() {
        cout << "---------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "---------------" << endl;
        }
    }

    Move minimax(char player) {
        char opponent = (player == YOU) ? COMPUTER_PLAYER : YOU;
        Move bestMove;
        int bestScore = (player == COMPUTER_PLAYER) ? -1000 : 1000;
        int score;

        if (isBoardFull() || checkWinner() != EMPTY_CELL) {
            bestScore = evaluate();
        } else {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == EMPTY_CELL) {
                        board[i][j] = player;
                        score = minimax(opponent).row;
                        if ((player == COMPUTER_PLAYER && score > bestScore) || (player == YOU && score < bestScore)) {
                            bestScore = score;
                            bestMove.row = i;
                            bestMove.col = j;
                        }
                        board[i][j] = EMPTY_CELL;
                    }
                }
            }
        }
        return bestMove;
    }

    int evaluate() {
        char winner = checkWinner();
        if (winner == COMPUTER_PLAYER)
            return 1;
        else if (winner == YOU)
            return -1;
        else
            return 0;
    }

    void playGame() {
        int row, col;
        
        Move move;

        while (true) {
            cout << "Enter your move [X] (row and column): ";
            cin >> row >> col;

            if (isMoveValid(row, col)) {
                board[row][col] = YOU;
                printBoard();
                if (checkWinner() == YOU) {
                    cout << "Congratulations You win." << endl;
                    break;
                } else if (isBoardFull()) {
                    cout << "DRAW:" << endl;
                    break;
                }

                move = minimax(COMPUTER_PLAYER);
                board[move.row][move.col] = COMPUTER_PLAYER;
                cout << "Computer move: " << move.row << " " << move.col << endl;
                printBoard();

                if (checkWinner() == COMPUTER_PLAYER) {
                    cout << "Computer wins." << endl;
                    break;
                } else if (isBoardFull()) {
                    cout << "DRAW: " << endl;
                    break;
                }
            } else {
                cout << "Invalid move,Try again." << endl;
            }
        }
    }
};

int main() {
    TICTACAI game;
    game.playGame();
    return 0;
}
