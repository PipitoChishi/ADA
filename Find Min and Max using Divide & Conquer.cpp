Find Min and Max using Divide & Conquer
Algorithm
Input: An array arr of size n.
Base Case:
If n == 1, return arr[0] as both min and max.
If n == 2, return min(arr[0], arr[1]) and max(arr[0], arr[1]).

Recursive Case:
Divide the array into two halves.
Recursively find minLeft, maxLeft for the left half.
Recursively find minRight, maxRight for the right half.

Compute:
minValue = min(minLeft, minRight).
maxValue = max(maxLeft, maxRight).
Return the final minValue and maxValue.


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findMinMax(vector<int>& arr, int left, int right, int& minVal, int& maxVal) {
    if (left == right) {
        minVal = maxVal = arr[left];
        return;
    }

    if (right - left == 1) {
        if (arr[left] < arr[right]) {
            minVal = arr[left];
            maxVal = arr[right];
        } else {
            minVal = arr[right];
            maxVal = arr[left];
        }
        return;
    }

    int mid = (left + right) / 2;
    int minLeft = INT_MAX, maxLeft = INT_MIN;
    int minRight = INT_MAX, maxRight = INT_MIN;
    
    findMinMax(arr, left, mid, minLeft, maxLeft);
    findMinMax(arr, mid + 1, right, minRight, maxRight);
    
    minVal = min(minLeft, minRight);
    maxVal = max(maxLeft, maxRight);
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 6, 2};
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    findMinMax(arr, 0, arr.size() - 1, minVal, maxVal);
    cout << "Min: " << minVal << ", Max: " << maxVal << endl;
    
    return 0;
}
