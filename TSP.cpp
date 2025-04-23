#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

const int INF = INT_MAX;

// Memoization cache to store computed g(i,S) values
unordered_map<string, int> memo;

// Helper function to generate a unique key for memoization
string makeKey(int current, vector<bool>& visited) {
    string key = to_string(current) + ":";
    for (bool v : visited) {
        key += v ? "1" : "0";
    }
    return key;
}


int g(vector<vector<int>>& costs, int current, vector<bool>& visited, int n, int count) {
    // Base case: all cities visited, return to start (city 0)
    if (count == n) {
        return costs[current][0];
    }

    string key = makeKey(current, visited);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int min_cost = INF;

    // Try all unvisited cities
    for (int next = 0; next < n; next++) {
        if (!visited[next] && costs[current][next] != INF) {
            visited[next] = true;
            int current_cost = costs[current][next] + g(costs, next, visited, n, count + 1);
            min_cost = min(min_cost, current_cost);
            visited[next] = false; // Backtrack
        }
    }

    memo[key] = min_cost;
    return min_cost;
}

int main() {
    
    int n = 4; 
    vector<vector<int>> costs = {
        {0, 5, 6, 8},   
        {5, 0, 10, 25},  
        {6, 10, 0, 15},  
        {8, 25, 15, 0}   
    };

    vector<bool> visited(n, false);
    visited[0] = true; 
    int min_cost = g(costs, 0, visited, n, 1);

    if (min_cost == INF) {
        cout << "No valid tour exists!" << endl;
    } else {
        cout << "Minimum TSP cost: " << min_cost << endl;
    }

    return 0;
}