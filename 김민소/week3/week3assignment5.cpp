#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    int x, y, dir, cost;
};

int main() {
    int W, H;
    cin >> W >> H;

    vector<string> board(H);
    vector<pair<int, int>> C;

    for (int i = 0; i < H; i++) {
        cin >> board[i];
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 'C') {
                C.push_back({i, j});
            }
        }
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, INF)));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    deque<Node> dq;

    int sx = C[0].first;
    int sy = C[0].second;
    int ex = C[1].first;
    int ey = C[1].second;

    for (int d = 0; d < 4; d++) {
        dist[sx][sy][d] = 0;
        dq.push_back({sx, sy, d, 0});
    }

    while (!dq.empty()) {
        Node cur = dq.front();
        dq.pop_front();

        if (dist[cur.x][cur.y][cur.dir] < cur.cost) continue;

        for (int nd = 0; nd < 4; nd++) {
            int nx = cur.x + dx[nd];
            int ny = cur.y + dy[nd];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny] == '*') continue;

            int nextCost = cur.cost;

            if (cur.dir != nd) {
                nextCost++;
            }

            if (dist[nx][ny][nd] > nextCost) {
                dist[nx][ny][nd] = nextCost;

                if (cur.dir == nd) {
                    dq.push_front({nx, ny, nd, nextCost});
                } else {
                    dq.push_back({nx, ny, nd, nextCost});
                }
            }
        }
    }

    int answer = INF;
    for (int d = 0; d < 4; d++) {
        answer = min(answer, dist[ex][ey][d]);
    }

    cout << answer;

    return 0;
}