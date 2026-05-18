// 문제 4. 레이저 거울
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int INF = 1000000000;

struct State { // row, column, direction
    int r; int c; int dir;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int W, H;
    cin >> W >> H;

    vector<string> board(H);

    for (int i = 0; i < H; i++) {
        cin >> board[i];
    }

    vector<pair<int, int> > points;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (board[r][c] == 'C') {
                points.push_back(make_pair(r, c));
            }
        }
    }

    pair<int, int> start = points[0];
    pair<int, int> target = points[1];

    vector<vector<vector<int> > > dist(
        H,
        vector<vector<int> >(W, vector<int>(4, INF))
    );

    deque<State> dq;

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    for (int dir = 0; dir < 4; dir++) {
        dist[start.first][start.second][dir] = 0;
        State s;
        s.r = start.first;
        s.c = start.second;
        s.dir = dir;
        dq.push_back(s);
    }

    while (!dq.empty()) {
        State cur = dq.front();
        dq.pop_front();

        int r = cur.r;
        int c = cur.c;
        int dir = cur.dir;

        for (int ndir = 0; ndir < 4; ndir++) {
            int nr = r + dr[ndir];
            int nc = c + dc[ndir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                continue;
            }

            if (board[nr][nc] == '*') {
                continue;
            }

            int cost;

            if (dir == ndir) { cost = 0; }
            else { cost = 1; }

            if (dist[nr][nc][ndir] > dist[r][c][dir] + cost) {
                dist[nr][nc][ndir] = dist[r][c][dir] + cost;

                State next;
                next.r = nr;
                next.c = nc;
                next.dir = ndir;

                if (cost == 0) {
                    dq.push_front(next);
                }
                else {
                    dq.push_back(next);
                }
            }
        }
    }

    int answer = INF;

    for (int dir = 0; dir < 4; dir++) {
        answer = min(answer, dist[target.first][target.second][dir]);
    }

    cout << answer << '\n';

    return 0;
}