#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int e;
        cin >> e;
        vector<vector<int>> graph(n);
        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(n, -1);
        queue<int> q;
        color[0] = 0;
        q.push(0);
        bool bipartite = true;

        while (!q.empty() && bipartite) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    bipartite = false;
                    break;
                }
            }
        }

        cout << (bipartite ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
    return 0;
}
