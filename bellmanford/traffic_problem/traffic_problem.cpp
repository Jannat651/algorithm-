
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tc = 1;
    while (cin >> n) {
        vector<long long> busy(n+1);
        for (int i = 1; i <= n; i++)
            cin >> busy[i];

        int r;
        cin >> r;

        vector<Edge> edges;
        while (r--) {
            int u, v;
            cin >> u >> v;
            long long w = (busy[v] - busy[u]);
            w = w * w * w;
            edges.push_back({u, v, w});
        }

        vector<long long> dist(n+1, INF);
        dist[1] = 0;

         for (int i = 0; i < n-1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

         vector<bool> neg(n+1, false);
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                neg[e.v] = true;
            }
        }

         for (int i = 0; i < n; i++) {
            for (auto &e : edges) {
                if (neg[e.u]) neg[e.v] = true;
            }
        }

        int q;
        cin >> q;

        cout << "Set #" << tc++ << "\n";
        while (q--) {
            int x;
            cin >> x;

            if (x < 1 || x > n || dist[x] == INF || dist[x] < 3 || neg[x])
                cout << "?\n";
            else
                cout << dist[x] << "\n";
        }
    }
}
