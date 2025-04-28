Algorithm: LCS using Dynamic Programming
Input: Two strings X of length m and Y of length n.
Output: Length of their Longest Common Subsequence (LCS) and the LCS itself.

Steps:
Initialization:
Create a 2D array c of size (m+1) × (n+1) to store the lengths of LCS.
Create another 2D array b of size (m+1) × (n+1) to store the directions for reconstruction:
'\\' for diagonal (match),
'^' for upward move,
'<' for leftward move.

Build the LCS Table:
For each character X[i-1] and Y[j-1]:
If X[i-1] == Y[j-1], then c[i][j] = c[i-1][j-1] + 1 and b[i][j] = '\\'.
Else, if c[i-1][j] >= c[i][j-1], then c[i][j] = c[i-1][j] and b[i][j] = '^'.
Else, c[i][j] = c[i][j-1] and b[i][j] = '<'.

Reconstruct LCS:
Start from c[m][n] and follow the directions stored in b:
If direction is '\\', print X[i-1] and move diagonally.
If '^', move up.
If '<', move left.
Continue until i == 0 or j == 0.
Print results:
Length of LCS: value of c[m][n].
Sequence: reconstructed using b.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void LCS_Length(const string &X, const string &Y, vector<vector<int>> &c, vector<vector<char>> &b) {
    int m = X.length();
    int n = Y.length();

    c.resize(m + 1, vector<int>(n + 1, 0));
    b.resize(m + 1, vector<char>(n + 1, ' '));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\'; // Diagonal
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '^'; // Up
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<'; // Left
            }
        }
    }
}


void Print_LCS(const vector<vector<char>> &b, const string &X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == '\\') {
        Print_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == '^') {
        Print_LCS(b, X, i - 1, j);
    } else {
        Print_LCS(b, X, i, j - 1);
    }
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

    vector<vector<int>> c;
    vector<vector<char>> b;

    LCS_Length(X, Y, c, b);

    cout << "Length of LCS: " << c[X.length()][Y.length()] << endl;
    cout << "LCS: ";
    Print_LCS(b, X, X.length(), Y.length());
    cout << endl;

    return 0;
}
