#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void MGP(int n, vector<vector<int>>& cost, vector<vector<int>>& adj) {
    vector<int> fdist(n + 1, INF);  // fdist[i] = min cost from i to destination
    vector<int> d(n + 1, -1);       // d[i] = next vertex on path from i

    fdist[n] = 0;  

   
    for (int j = n - 1; j >= 1; j--) {
        for (int r : adj[j]) {
            if (cost[j][r] != INF && fdist[r] != INF) {
                int temp = cost[j][r] + fdist[r];
                if (temp < fdist[j]) {
                    fdist[j] = temp;
                    d[j] = r; // best next step from j
                }
            }
        }
    }

    // minimum cost 
    cout << "Minimum cost from 1 to " << n << ": " << fdist[1] << endl;

  
    vector<int> path;
    path.push_back(1);              // P(1) = 1

    while (path.back() != n) {      // P(k) = n
        int last = path.back();     // P(j-1)
        path.push_back(d[last]);    // P(j) = d(P(j-1))
    }

  
    cout << "Minimum cost path: "; // for path 
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int n = 7; 


    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> adj(n + 1);

    
    auto addEdge = [&](int u, int v, int w) {
        cost[u][v] = w;
        adj[u].push_back(v);
    };

  
    addEdge(1, 2, 2);
    addEdge(1, 3, 1);
    addEdge(2, 4, 2);
    addEdge(2, 5, 3);
    addEdge(3, 5, 9);
    addEdge(4, 6, 6);
    addEdge(5, 6, 7);
    addEdge(6, 7, 4);

    MGP(n, cost, adj);

    return 0;
}