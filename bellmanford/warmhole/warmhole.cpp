
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;
    while (C--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++)
            cin >> edges[i].u >> edges[i].v >> edges[i].w;

        vector<int> dist(n, 0);
        bool negCycle = false;

        for (int i = 0; i < n; i++) {
            for (auto &e : edges) {
                if (dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                    if (i == n-1) negCycle = true;
                }
            }
        }

        cout << (negCycle ? "possible" : "not possible") << "\n";
    }
}
