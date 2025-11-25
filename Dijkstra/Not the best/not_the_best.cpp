#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<vector<pair<int,int>>> g;

vector<long long> dijkstra(int start, int n) {
    vector<long long> dist(n+1, INF);
    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;

        for (auto [v,w] : g[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, R;
        cin >> N >> R;

        g.assign(N+1, {});
        vector<tuple<int,int,int>> edges;

        while (R--) {
            int u,v,w;
            cin >> u >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            edges.push_back({u,v,w});
        }

        auto d1 = dijkstra(1, N);
        auto dN = dijkstra(N, N);

        long long best = d1[N];
        long long second = INF;

        for (auto &[u,v,w] : edges) {
            long long p1 = d1[u] + w + dN[v];
            long long p2 = d1[v] + w + dN[u];

            if (p1 > best) second = min(second, p1);
            if (p2 > best) second = min(second, p2);
        }

        cout << "Case " << tc << ": " << second << "\n";
    }
}
