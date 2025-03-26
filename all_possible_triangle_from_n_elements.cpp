Generate All Possible Triangles from n Elements
Algorithm
Input: A list of n integers representing side lengths.
Iterate through all triplets (a, b, c) in the list.

Check if they satisfy the triangle inequality:
a + b > c
b + c > a
c + a > b
If the conditions hold, print (a, b, c) as a valid triangle.
Continue until all valid triangles are found.

#include <iostream>
#include <vector>

using namespace std;

void generateTriangles(vector<int>& arr) {
    int n = arr.size();
    cout << "Possible triangles:\n";
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[k] + arr[i] > arr[j])
                    cout << arr[i] << ", " << arr[j] << ", " << arr[k] << "\n";
            }
        }
    }
}

int main() {
    vector<int> arr = {4, 6, 3, 7, 10, 12};
    generateTriangles(arr);
    return 0;
}
