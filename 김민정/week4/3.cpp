#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    
    struct Edge { int u, v; double w; };
    vector<Edge> edges(M);

    for (auto& [u, v, w] : edges) {
        double r;
        cin >> u >> v >> r;
        w = -log(r);   
    }

    
    vector<double> dist(N + 1, INF);
    dist[1] = 0.0;

    for (int i = 0; i < N - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    
    
    bool arbitrage = false;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            arbitrage = true;
            break;
        }
    }

    cout << (arbitrage ? "YES" : "NO") << "\n";

    return 0;
}
