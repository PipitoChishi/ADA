Algorithm:
Initialize:
Set the distance to the source node as 0 and all others as ∞.
Use a priority queue (min-heap) to store vertices along with their current shortest distance.

Process Nodes:
Extract the node with the smallest known distance.
Update distances of its adjacent nodes if a shorter path is found.
Push updated distances into the priority queue.

Repeat Until All Nodes Processed:
Continue updating and extracting nodes until the priority queue is empty.
Return the Shortest Distance to Each Node.


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>> &graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If the current distance is outdated, skip processing
        if (d > dist[u]) continue;

        // Debugging: Show processing node
        cout << "Processing Node: " << u << " with Distance: " << d << endl;

        for (size_t i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            // Debugging: Show each edge being processed
            cout << "Checking edge " << u << " -> " << v << " with weight " << w << endl;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});

                // Debugging: Show distance update
                cout << "Updated distance of " << v << " to " << dist[v] << endl;
            }
        }
    }

    // Print final shortest distances
    cout << "\nVertex Distance from Source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " -> INF" << endl;
        else
            cout << i << " -> " << dist[i] << endl;
    }
}

int main() {
    int vertices = 4;
    vector<vector<pair<int, int>>> graph(vertices);

    // Add graph edges (u -> v with weight w)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
