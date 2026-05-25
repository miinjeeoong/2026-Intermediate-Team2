#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, W;
    cin >> N >> R >> W;

    struct Edge { int u, v; long long w; };
    vector<Edge> edges;
    edges.reserve(R * 2 + W);

    
    for (int i = 0; i < R; i++) {
        int u, v; long long c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        edges.push_back({v, u, c});
    }

    
    for (int i = 0; i < W; i++) {
        int u, v; long long c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    int M = (int)edges.size();

    
    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    
    
    vector<vector<int>> adj(N + 1);
    for (auto& [u, v, w] : edges)
        adj[u].push_back(v);

    vector<bool> in_neg_cycle(N + 1, false);
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v])
            in_neg_cycle[v] = true;
    }

    
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (in_neg_cycle[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (!in_neg_cycle[nxt]) {
                in_neg_cycle[nxt] = true;
                q.push(nxt);
            }
        }
    }

    
    if (dist[N] == INF)         cout << "INF\n";
    else if (in_neg_cycle[N])   cout << "-INF\n";
    else                        cout << dist[N] << "\n";

    return 0;
}
