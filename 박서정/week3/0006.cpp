// 문제 6. 가벼운 길 찾기
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int> > > graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    vector<int> dist(N + 1, INF);
    deque<int> dq;

    dist[1] = 0;
    dq.push_back(1);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < (int)graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;

                if (cost == 0) { dq.push_front(next); }
                else { dq.push_back(next); }
            }
        }
    }

    cout << dist[N] << '\n';

    return 0;
}