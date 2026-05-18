// 문제 3. 검은 방 바꾸기
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

    int N;
    cin >> N;

    vector<string> room(N);

    for (int i = 0; i < N; i++) {
        cin >> room[i];
    }

    vector<vector<int> > dist(N, vector<int>(N, INF));
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

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            int cost;

            if (room[nr][nc] == '1') {
                cost = 0;
            }
            else { cost = 1; }

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

    cout << dist[N - 1][N - 1] << '\n';

    return 0;
}