#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F;
    cin >> F;

    while (F--) {
        int N, M, B;
        cin >> N >> M >> B;

        struct Edge { int u, v; long long w; };
        vector<Edge> edges;
        edges.reserve(M * 2 + B);

        
        for (int i = 0; i < M; i++) {
            int s, e; long long t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        
        for (int i = 0; i < B; i++) {
            int s, e; long long t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        
        
        
        vector<long long> dist(N + 1, 0);

        
        for (int i = 0; i < N - 1; i++) {
            for (auto& [u, v, w] : edges) {
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        
        bool neg_cycle = false;
        for (auto& [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                neg_cycle = true;
                break;
            }
        }

        cout << (neg_cycle ? "YES" : "NO") << "\n";
    }

    return 0;
}
