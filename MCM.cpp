#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void printOptimalParens(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;  
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);      
        printOptimalParens(s, s[i][j] + 1, j);   
        cout << ")";
    }
}


int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;  // Number of matrices
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0)); 
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0)); 

  
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

  
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

        
            for (int k = i; k < j; k++) {
                // Cost calculation (matches your notes: q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j])
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                // Update minimum cost and split index
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;  // Record the optimal split
                }
            }
        }
    }

   
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << endl;

    return m[1][n];  }

int main() {
    
    vector<int> dimensions = {10, 20, 5, 10, 30};  

    cout << "Matrix Dimensions: ";
    for (int d : dimensions) cout << d << " ";
    cout << endl;

    int minCost = matrixChainOrder(dimensions);
    cout << "Minimum Scalar Multiplications: " << minCost << endl;

    return 0;
}