#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
typedef pair<int, int> P;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> grid[i];
    }

    vector<vector<int>> dist(N, vector<int>(M, -1));
    deque<P> dq;

    dq.push_back({ 0, 0 });
    dist[0][0] = 0;

    while (!dq.empty())
    {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        if (x == N - 1 && y == M - 1)
        {
            cout << dist[x][y] << "\n";
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (dist[nx][ny] == -1)
                {
                    if (grid[nx][ny] == '0')
                    {
                        dist[nx][ny] = dist[x][y];
                        dq.push_front({ nx, ny });
                    }
                    else if (grid[nx][ny] == '1')
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        dq.push_back({ nx, ny });
                    }
                }
            }
        }
    }

    return 0;
}
#endif