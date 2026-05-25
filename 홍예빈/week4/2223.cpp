// 정올 2223번 블랙홀 - 벨만 포드 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int F;
    cin >> F;

    while(F--) {

        int N, M, B;
        cin >> N >> M >> B;

        vector<tuple<int,int,int>> edges;

        for(int i=0;i<M;i++) {
            int S,E,T;
            cin >> S >> E >> T;

            edges.push_back({S,E,T});
            edges.push_back({E,S,T});
        }

        for(int i=0;i<B;i++) {
            int S,E,T;
            cin >> S >> E >> T;

            edges.push_back({S,E,-T});
        }

        vector<int> dist(N+1,0);

        bool negativeCycle = false;

        for(int i=1;i<=N;i++) {

            bool updated = false;

            for(auto &[u,v,w] : edges) {

                if(dist[v] > dist[u] + w) {

                    dist[v] = dist[u] + w;
                    updated = true;

                    if(i==N) {
                        negativeCycle = true;
                    }
                }
            }

            if(!updated) break;
        }

        cout << (negativeCycle ? "YES" : "NO") << '\n';
    }

    return 0;
}