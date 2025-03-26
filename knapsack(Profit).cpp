Knapsack Sorted by Value (Profit)
Algorithm:
Sort items in descending order of value (profit).
Initialize totalValue = 0.

For each item in the sorted list:
If capacity >= item.weight, take the item fully:
Reduce capacity by item.weight.
Increase totalValue by item.value.

Else, take fractional part of the item:
Add (item.value / item.weight) * capacity to totalValue.
Set capacity = 0 (knapsack is full).
Break loop.
Return totalValue as the maximum profit.



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
};

// Sorting by value (profit)
bool sortByValue(Item a, Item b) { 
    return a.value > b.value; 
}

// Fractional Knapsack function
double knapsackFractional(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), sortByValue);
    double totalValue = 0.0;
    for (auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += (double)item.value / item.weight * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    cout << "Knapsack using Value Sorting: " << knapsackFractional(items, capacity) << endl;
    return 0;
}
v
