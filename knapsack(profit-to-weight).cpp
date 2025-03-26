Knapsack Sorted by Profit-to-Weight Ratio
Algorithm:
Sort items in descending order of profit-to-weight ratio (value/weight).
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

bool sortByRatio(Item a, Item b) { 
    return (double)a.value / a.weight > (double)b.value / b.weight; 
}

double knapsackFractional(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), sortByRatio);
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
    cout << "Knapsack using Profit/Weight Ratio Sorting: " << knapsackFractional(items, capacity) << endl;
    return 0;
}
