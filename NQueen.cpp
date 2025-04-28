Algorithm: Solving N-Queens Problem using Backtracking
Input: An integer n — the number of queens and the size of the chessboard (n × n).
Output: All possible ways to place n queens on an n × n chessboard such that no two queens attack each other.

Steps:
Initialize:
x[k] represents the column where the queen is placed in the k-th row.

Placement Check (Place function):
For the current row k, and column i, check for conflicts:
Same column: if x[j] == i (some previous queen is in the same column).
Same diagonal: if abs(x[j] - i) == abs(j - k) (some previous queen is in the same diagonal).
If any conflict occurs, return false, otherwise return true.

Recursive Solution (NQueen function):
Try placing the queen in each column (from 1 to n) for the current row k.

If it’s safe (Place(k, i) returns true):
Place the queen (x[k] = i).
If all queens are placed (k == n), print the solution.
Otherwise, call NQueen(k+1) to place the next queen.

Start the process:
In main(), take user input n and call NQueen(1).


#include <iostream>
#include <cmath>
using namespace std;

int x[100]; //  column position of the row k 
int n;     

bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; 
        }
    }
    return true;
}

void NQueen(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i; 
            if (k == n) {
             
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                NQueen(k + 1); 
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;
    NQueen(1);
    return 0;
}
