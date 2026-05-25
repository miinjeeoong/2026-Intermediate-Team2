// 문제3 환전 차익거래 - 벨만 포드 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<tuple<int,int,double>> edges;

    for (int i = 0; i < M; i++) {
        int u, v;
        double r;

        cin >> u >> v >> r;

        edges.push_back({u, v, -log(r)});
    }

    vector<double> dist(N + 1, 0.0);

    for (int i = 1; i <= N - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &[u, v, w] : edges) {
        if (dist[v] > dist[u] + w) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}