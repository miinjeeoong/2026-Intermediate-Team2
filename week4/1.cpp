#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    
    vector<tuple<int, int, int>> edges(M);
    for (auto& [u, v, w] : edges)
        cin >> u >> v >> w;

    
    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    
    for (int i = 0; i < N - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    
    bool neg_cycle = false;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            neg_cycle = true;
            break;
        }
    }

    if (neg_cycle) {
        cout << -1 << "\n";
        return 0;
    }

    
    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else                 cout << dist[i] << "\n";
    }

    return 0;
}
