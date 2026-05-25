// 문제1 음수 간선의 최단 거리 - 벨만 포드 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &[u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
