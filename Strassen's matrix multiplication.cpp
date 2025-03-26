Algorithm:
Base Case: If the matrix is of size 1×1, return the product of the single elements.

Divide: Split the input matrices 𝐴 and B into four submatrices of size 𝑛/2×𝑛/2
Calculate 7 Matrix Products:
P1 = A11 × (B12 − B22)
P2 = (A11 + A12) × B22
P3 = (A21 + A22) × B11
P4 = A22 × (B21 − B11)
P5 = (A11 + A22) × (B11 + B22)
P6 = (A12 − A22) × (B21 + B22)
P7 = (A11 − A21) × (B11 + B12)
Combine Results: Compute the final quadrants of the result matrix C:
C11 = P5 + P4 − P2 + P6
C12 = P1 + P2
C21 = P3 + P4
C22 = P5 + P1 − P3 − P7
return C

#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to subtract two matrices
vector<vector<int>> subMatrix(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen’s matrix multiplication
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)), A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)), B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    auto P1 = strassen(A11, subMatrix(B12, B22));
    auto P2 = strassen(addMatrix(A11, A12), B22);
    auto P3 = strassen(addMatrix(A21, A22), B11);
    auto P4 = strassen(A22, subMatrix(B21, B11));
    auto P5 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    auto P6 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));
    auto P7 = strassen(subMatrix(A11, A21), addMatrix(B11, B12));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + newSize] = P1[i][j] + P2[i][j];
            C[i + newSize][j] = P3[i][j] + P4[i][j];
            C[i + newSize][j + newSize] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return C;
}

// Function to print matrix
void printMatrix(vector<vector<int>> matrix) {
    for (auto row : matrix) {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Resultant Matrix:\n";
    vector<vector<int>> C = strassen(A, B);
    printMatrix(C);

    return 0;
}
