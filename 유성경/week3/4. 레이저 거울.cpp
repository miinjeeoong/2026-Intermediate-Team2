#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

typedef struct State
{
    int x;
    int y;
    int dir;
}S;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W, H;
    cin >> W >> H;

    vector<string> grid(H);
    int sx = -1;
    int sy = -1;
    int ex = -1;
    int ey = -1;

    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == 'C')
            {
                if (sx == -1)
                {
                    sx = i;
                    sy = j;
                }
                else
                {
                    ex = i;
                    ey = j;
                }
            }
        }
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, -1)));
    deque<S> dq;

    for (int i = 0; i < 4; ++i)
    {
        dist[sx][sy][i] = 0;
        dq.push_back({ sx, sy, i });
    }

    int ans = -1;

    while (!dq.empty())
    {
        State curr = dq.front();
        dq.pop_front();

        if (curr.x == ex && curr.y == ey)
        {
            if (ans == -1 || dist[curr.x][curr.y][curr.dir] < ans)
            {
                ans = dist[curr.x][curr.y][curr.dir];
            }

            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W)
            {
                if (grid[nx][ny] != '*')
                {
                    int cost = (curr.dir == i) ? 0 : 1;
                    int new_dist = dist[curr.x][curr.y][curr.dir] + cost;

                    if (dist[nx][ny][i] == -1 || new_dist < dist[nx][ny][i])
                    {
                        dist[nx][ny][i] = new_dist;
                        if (cost == 0)
                        {
                            dq.push_front({ nx, ny, i });
                        }
                        else
                        {
                            dq.push_back({ nx, ny, i });
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif