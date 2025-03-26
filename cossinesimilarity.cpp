Algorithm:
1. Initialize Variables
Set dot_product = 0, magnitude_A = 0, and magnitude_B = 0.
  
2. Compute Dot Product and Magnitudes Simultaneously
For each index i from 0 to n-1:
Compute dot_product += A[i] * B[i].
Compute magnitude_A += A[i] * A[i].
Compute magnitude_B += B[i] * B[i].

3. Compute Final Magnitudes
Compute magnitude_A = sqrt(magnitude_A).
Compute magnitude_B = sqrt(magnitude_B).

4. Handle Edge Case
If magnitude_A == 0 or magnitude_B == 0, return 0 (to avoid division by zero).

5. Compute Cosine Similarity
Compute cosine_similarity = dot_product / (magnitude_A * magnitude_B).

6. Return the Result
Output the cosine_similarity value.


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double dotProduct(const vector<double>& A, const vector<double>& B) {
    double product = 0;
    for (size_t i = 0; i < A.size(); i++) {
        product += A[i] * B[i];
    }
    return product;
}

double magnitude(const vector<double>& A) {
    double sum = 0;
    for (double val : A) {
        sum += val * val;
    }
    return sqrt(sum);
}

double cosineSimilarity(const vector<double>& A, const vector<double>& B) {
    double dotProd = dotProduct(A, B);
    double magA = magnitude(A);
    double magB = magnitude(B);

    if (magA == 0 || magB == 0) {
        cerr << "Error: One of the vectors has zero magnitude!" << endl;
        return 0;
    }

    return dotProd / (magA * magB);
}

int main() {
    vector<double> vec1 = {1, 2, 3};
    vector<double> vec2 = {4, 5, 6};

    double similarity = cosineSimilarity(vec1, vec2);
    cout << "Cosine Similarity: " << similarity << endl;

    return 0;
}
