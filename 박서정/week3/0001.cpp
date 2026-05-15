// 문제 1. 순간이동 통로
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 1000000000;
const int MAX = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX + 1, INF);
    deque<int> dq;

    dist[N] = 0;
    dq.push_back(N);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        int next = cur * 2;
        if (next <= MAX && dist[next] > dist[cur]) {
            dist[next] = dist[cur];
            dq.push_front(next);
        }

        next = cur - 1;
        if (next >= 0 && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }

        next = cur + 1;
        if (next <= MAX && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
    }

    cout << dist[K] << '\n';

    return 0;
}