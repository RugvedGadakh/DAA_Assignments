#include <iostream>
#include <cmath>
using namespace std;

int board[20], count;
void print(int n) {
    cout << "\n\nSolution: " << ++count << ": \n\n";

    for (int i = 1; i <= n; i++) {
        cout << "\t" << i;
    }

    for (int i = 1; i <= n; i++) {
        cout << "\n\n" << i;
        for (int j = 1; j <= n; j++) {
            if (board[i] == j) {
                cout << "\tQ";
            }
            else {
                cout << "\t-";
            }
        }
    }
}

int place(int row, int column) {
    for (int i = 1; i <= row - 1; ++i) {
        // Checking column and diagonal conflicts
        if ((board[i] == column) || (abs(board[i] - column) == abs(i - row)))
            return 0;
    }
    return 1; // No conflicts
}

void queen(int row, int n) {
    for (int column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column; // No conflicts, so place queen
            if (row == n) // Dead end
                print(n);   // Printing the board configuration
            else // Try queen with the next position
                queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    count = 0;
    queen(1, n);

    return 0;
}



// Problem Statement: - Write a recursive program to find the solution of placing n queens on
// chessboard so that no two queens attack each other using Backtracking
// Objective: - In chess, a queen can move as far as she pleases, horizontally, vertically, or diagonally. A chess board has 8 rows and 8
// columns. The standard 8 by 8 Queen’s problem asks how to place 8
// queens on an ordinary chess board so that none of them can hit
// any other in one move.
// Theory: -
// The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so
// that no two queens threaten each other. Thus, a solution requires that no two queens share the
// same row, column, or diagonal. The eight queens puzzle is an example of the more general nqueens problem of placing n queens on an n×n chessboard, where solutions exist for all natural
// numbers n with the exception of n=2 and n=3. The eight queens puzzle has 92 distinct solutions.
// If solutions that differ only by symmetry operations (rotations and reflections) of the board are
// counted as one, the puzzle has 12 fundamental solutions.
// Here we are solving it for N queens in NxN chess board.
// (Explain 5 queens problem with Diagram)
// Approach:
//  Create a solution matrix of the same structure as chess board.
//  Whenever place a queen in the chess board, mark that particular cell in solution matrix.
//  At the end print the solution matrix, the marked cells will show the positions of the queens
// in the chess board.
// Algorithm
// Place the queens column wise, start from the left most column
// 1. If all queens are placed.
// 1. return true and print the solution matrix.
// 2. Else
// 1. Try all the rows in the current column.
// 2. Check if queen can be placed here safely if yes mark the current cell in solution
// matrix as 1 and try to solve the rest of the problem recursively.
// 3. If placing the queen in above step leads to the solution return true.
// 4. If placing the queen in above step does not lead to the solution , BACKTRACK,
// mark the current cell in solution matrix as 0 and return false.
// 3. If all the rows are tried and nothing worked, return false and print NO SOLUTION.
// Better Solution: If you notice in solution matrix, at every row we have only one entry as 1 and rest
// of the entries are 0. Solution matrix takes O(N2) space. We can reduce it to O(N). We will solve it
// by taking one dimensional array and consider solution[1] = 2 as “Queen at 1st row is placed at 2nd
// column