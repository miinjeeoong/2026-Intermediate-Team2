#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> dist(100001, -1);
    deque<int> dq;

    dq.push_back(N);
    dist[N] = 0;

    while (!dq.empty())
    {
        int curr = dq.front();
        dq.pop_front();

        if (curr == K)
        {
            cout << dist[curr] << "\n"; 
            break;
        }

        int next_teleport = curr * 2;
        if (next_teleport >= 0 && next_teleport <= 100000) 
        {
            if (dist[next_teleport] == -1)
            {
                dist[next_teleport] = dist[curr];
                dq.push_front(next_teleport);
            }
        }

        int dirs[] = { curr - 1, curr + 1 };
        for (int i = 0; i < 2; ++i)
        {
            int next_walk = dirs[i];
            if (next_walk >= 0 && next_walk <= 100000) 
            {
                if (dist[next_walk] == -1)
                {
                    dist[next_walk] = dist[curr] + 1;
                    dq.push_back(next_walk);
                }
            }
        }
    }

    return 0;
}
#endif