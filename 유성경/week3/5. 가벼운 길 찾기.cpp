#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef struct Edge
{
    int to;
    int cost;
}E;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<E>> adj(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<int> dist(N + 1, -1);
    deque<int> dq;

    dq.push_back(1);
    dist[1] = 0;

    while (!dq.empty())
    {
        int curr = dq.front();
        dq.pop_front();

        if (curr == N)
        {
            cout << dist[curr] << "\n";
            break;
        }

        for (int i = 0; i < adj[curr].size(); ++i)
        {
            int next_node = adj[curr][i].to;
            int cost = adj[curr][i].cost;

            if (dist[next_node] == -1 || dist[curr] + cost < dist[next_node])
            {
                dist[next_node] = dist[curr] + cost;

                if (cost == 0)
                {
                    dq.push_front(next_node);
                }
                else
                {
                    dq.push_back(next_node);
                }
            }
        }
    }

    return 0;
}
#endif