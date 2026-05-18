#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    const int INF = 1e9;
    vector<int> dist(N + 1, INF);

    deque<int> dq;
    dist[1] = 0;
    dq.push_back(1);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (auto [next, cost] : graph[cur]) {
            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;

                if (cost == 0) {
                    dq.push_front(next);
                } else {
                    dq.push_back(next);
                }
            }
        }
    }

    cout << dist[N];

    return 0;
}