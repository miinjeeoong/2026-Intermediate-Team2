// 순간이동 통로 - 0-1 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    queue<pair<int, int>> q;
    vector<int> dis(100001, INT_MAX);
    cin >> n >> k;

    q.push({n, 0});
    dis[n] = 0;
    if(n == k) {
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    while(true) {
        int q_size = q.size();
        int a = 0;
        while(q_size--) {
            int cur_node = q.front().first;
            int cur_dist = q.front().second;
            q.pop();

            if(cur_node - 1 == k) a++;
            if(cur_node + 1 == k) a++;
            if(cur_node * 2 == k) a++;

            if(cur_node - 1 >= 0 && cur_dist + 1 <= dis[cur_node - 1]) {
                dis[cur_node - 1] = cur_dist + 1;
                q.push({cur_node - 1, cur_dist + 1});
            }
            if(cur_node + 1 <= 100000 && cur_dist + 1 <= dis[cur_node + 1]) {
                dis[cur_node + 1] = cur_dist + 1;
                q.push({cur_node + 1, cur_dist + 1});
            }
            if(cur_node * 2 <= 100000 && cur_dist + 1 <= dis[cur_node * 2]) {
                dis[cur_node * 2] = cur_dist + 1;
                q.push({cur_node * 2, cur_dist + 1});
            }
        }
        if(a) {
            cout << q.front().second << "\n";
            cout << a << "\n";
            break;
        }
    }
    return 0;
}