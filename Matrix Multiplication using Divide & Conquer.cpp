Matrix Multiplication using Divide & Conquer
Algorithm:
Base Case:
If the matrices are 1×1, return their product.
Divide the input matrices A and B into 4 submatrices each.

Recursively multiply corresponding submatrices using Divide & Conquer:
Compute four partial matrices:
C11, C12, C21, C22.
Combine results to obtain the final matrix.
Return the resultant matrix.


#include <iostream>
using namespace std;

void multiplyMatrix(int A[2][2], int B[2][2], int C[2][2]) {
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    multiplyMatrix(A, B, C);

    cout << "Result Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
