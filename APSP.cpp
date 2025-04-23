#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; 
void APSP(int n, vector<vector<int>> &graph) {
    
    vector<vector<int>> dist = graph;

   
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

  
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected.\n";
            return;
        }
    }

  
    cout << "All Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

   
    vector<vector<int>> graph(n, vector<int>(n, INF));

 
    for (int i = 0; i < n; ++i)
        graph[i][i] = 0;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // For undirected graphs, also set graph[v][u] = w;
    }

APSP(n, graph);

    return 0;
}