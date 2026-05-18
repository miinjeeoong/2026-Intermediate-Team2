// 레이저 거울 - 0-1 BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int w, h;
char map[101][101];
int visited[101][101];
int d[101][101];
vector<pair<int, int>> c;
queue<pair<int, int>> q;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main()
{
    cin >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'C')
                c.push_back({i, j});
        }
    }

    int sy = c[0].first;
    int sx = c[0].second;
    q.push({sy, sx});

    visited[sy][sx] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            while (ny >= 0 && nx >= 0 && ny < h && nx < w && map[ny][nx] != '*')
            {
                if (!visited[ny][nx])
                {
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                    d[ny][nx] = d[y][x] + 1;
                }
                ny += dy[i];
                nx += dx[i];
            }
        }
    }

    cout << d[c[1].first][c[1].second] - 1;
}