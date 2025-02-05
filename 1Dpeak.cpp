#include<iostream>
using namespace std;

int peak(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
       return arr[mid]; 

    if (arr[mid] < arr[mid - 1])
    {
        return peak(arr, low, mid - 1);
    } 
    else
    {
        return peak(arr, mid + 1, high);
    }
}
int main()
 {
    int arr[] = {7, 23, 5, 56, 38, 60};
    //int arr[] = {12, 8, 1, 9, 4, 10, 12, 11, 7};
    int low = 0, high = 0;
    
    int value = peak(arr, low, high);
    cout << "Peak is " << value << endl;
    return 0;
}
 
