// 문제4 워프 게이트 - 벨만 포드 알고리즘
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, W;
    cin >> N >> R >> W;

    vector<tuple<int,int,int>> edges;
    vector<vector<int>> revGraph(N+1);

    for(int i=0;i<R;i++){
        int u,v,c;
        cin >> u >> v >> c;

        edges.push_back({u,v,c});
        edges.push_back({v,u,c});

        revGraph[v].push_back(u);
        revGraph[u].push_back(v);
    }

    for(int i=0;i<W;i++){
        int u,v,c;
        cin >> u >> v >> c;

        edges.push_back({u,v,c});

        revGraph[v].push_back(u);
    }

    vector<bool> canReachN(N+1,false);
    queue<int> q;

    q.push(N);
    canReachN[N]=true;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int prev : revGraph[cur]){
            if(!canReachN[prev]){
                canReachN[prev]=true;
                q.push(prev);
            }
        }
    }

    vector<long long> dist(N+1,INF);
    dist[1]=0;

    for(int i=1;i<=N-1;i++){
        for(auto &[u,v,w] : edges){

            if(dist[u]==INF) continue;

            if(dist[v] > dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(auto &[u,v,w] : edges){

        if(dist[u]==INF) continue;

        if(dist[v] > dist[u]+w){

            if(canReachN[v]){
                cout << "-INF\n";
                return 0;
            }
        }
    }

    if(dist[N]==INF)
        cout << "INF\n";
    else
        cout << dist[N] << '\n';

    return 0;
}