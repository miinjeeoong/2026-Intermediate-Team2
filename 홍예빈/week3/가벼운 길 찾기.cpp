// 가벼운 길 찾기 - 0-1 BFS
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> dist(N + 1, INT_MAX);
    deque<int> dq;

    dist[1] = 0;
    dq.push_back(1);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (auto next : graph[cur]) {
            int nxt = next.first;
            int cost = next.second;

            if (dist[nxt] > dist[cur] + cost) {
                dist[nxt] = dist[cur] + cost;

                if (cost == 0)
                    dq.push_front(nxt);
                else
                    dq.push_back(nxt);
            }
        }
    }

    cout << dist[N] << '\n';

    return 0;
}