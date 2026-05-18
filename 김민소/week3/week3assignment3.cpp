#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> room(N);
    for (int i = 0; i < N; i++) {
        cin >> room[i];
    }

    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>(N, INF));

    deque<pair<int, int>> dq;

    dist[0][0] = 0;
    dq.push_back({0, 0});

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            int cost = (room[nx][ny] == '0');

            if (dist[nx][ny] > dist[x][y] + cost) {
                dist[nx][ny] = dist[x][y] + cost;

                if (cost == 0) {
                    dq.push_front({nx, ny});
                } else {
                    dq.push_back({nx, ny});
                }
            }
        }
    }

    cout << dist[N - 1][N - 1];

    return 0;
}