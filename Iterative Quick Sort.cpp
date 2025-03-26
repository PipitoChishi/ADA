Iterative Quick Sort
Algorithm
Input: An array arr of size n.
Initialize a stack and push the range (0, n-1).

While the stack is not empty:
Pop (low, high).
Choose arr[high] as the pivot.

Partition the array:
Move elements smaller than the pivot to the left.
Move elements greater than the pivot to the right.
Push (low, p-1) and (p+1, high) onto the stack.
Repeat until all elements are sorted.
Output the sorted array.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void iterativeQuickSort(vector<int>& arr) {
    stack<pair<int, int>> st;
    st.push({0, arr.size() - 1});
    
    while (!st.empty()) {
        int low = st.top().first;
        int high = st.top().second;
        st.pop();
        
        if (low < high) {
            int p = partition(arr, low, high);
            st.push({low, p - 1});
            st.push({p + 1, high});
        }
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    iterativeQuickSort(arr);
    
    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    return 0;
}
