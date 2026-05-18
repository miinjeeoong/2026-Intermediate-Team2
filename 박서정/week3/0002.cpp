#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<string> maze(N);

    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    vector<vector<int> > dist(N, vector<int>(M, INF));
    deque<pair<int, int> > dq;

    dist[0][0] = 0;
    dq.push_back(make_pair(0, 0));

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        int r = cur.first;
        int c = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }


            int cost = maze[nr][nc] - '0';

            if (dist[nr][nc] > dist[r][c] + cost) {
                dist[nr][nc] = dist[r][c] + cost;

                if (cost == 0) {
                    dq.push_front(make_pair(nr, nc));
                }
                else {
                    dq.push_back(make_pair(nr, nc));
                }
            }
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}