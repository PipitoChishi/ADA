Knapsack Sorted by Weight
Algorithm:
Sort items in ascending order of weight.
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

// Sorting by weight
bool sortByWeight(Item a, Item b) { 
    return a.weight < b.weight; 
}

double knapsackFractional(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), sortByWeight);
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
    cout << "Knapsack using Weight Sorting: " << knapsackFractional(items, capacity) << endl;
    return 0;
}
