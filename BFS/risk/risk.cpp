#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // for setw

using namespace std;

vector<vector<int>> adj(21); // adjacency list for nodes 1 to 20

int bfs(int start, int end) {
    vector<int> dist(21, -1); // distance from start, -1 means unvisited
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) return dist[u]; // shortest path found

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return -1; // no path found
}

int main() {
    int numNeighbors, neighbor;
    int testSet = 1;

    while (cin >> numNeighbors) {
        // Clear adjacency list for new test set
        for (auto &v : adj) v.clear();

        // Read neighbors for node 1
        for (int j = 0; j < numNeighbors; ++j) {
            cin >> neighbor;
            adj[1].push_back(neighbor);
            adj[neighbor].push_back(1);
        }

        // Read neighbors for nodes 2 to 19
        for (int i = 2; i <= 19; ++i) {
            cin >> numNeighbors;
            for (int j = 0; j < numNeighbors; ++j) {
                cin >> neighbor;
                adj[i].push_back(neighbor);
                adj[neighbor].push_back(i);
            }
        }

        int N; // number of queries
        cin >> N;

        cout << "Test Set #" << testSet++ << "\n";

        int start, end;
        for (int i = 0; i < N; ++i) {
            cin >> start >> end;
            int result = bfs(start, end);
            cout << setw(2) << start << " to " << setw(2) << end << ": " << result << "\n";
        }
        cout << "\n";
    }

    return 0;
}

