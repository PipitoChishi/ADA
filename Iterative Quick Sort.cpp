Iterative Quick Sort
Algorithm:
Initialize an empty stack and push the range (low, high).

While the stack is not empty:
Pop (low, high).

Partition the array around a pivot:
Move elements smaller than pivot to the left.
Move elements greater than pivot to the right.
Push left and right subarrays (low, p-1) and (p+1, high) onto the stack.
Repeat until the stack is empty (all elements sorted).
Return the sorted array.

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
