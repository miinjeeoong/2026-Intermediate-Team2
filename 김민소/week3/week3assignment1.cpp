#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;

    const int MAX=100000;
    int dist[MAX+1];

    for(int i=0; i<=MAX; i++){
        dist[i]=1e9;
    }

    deque<int> dq;
    dq.push_back(N);
    dist[N]=0;

    while(!dq.empty()){
        int x=dq.front();
        dq.pop_front();

        if(x==K){
            cout<<dist[x];
            return 0;
        }

        if(2 * x <= MAX&&dist[2*x]>dist[x]){
            dist[2*x]=dist[x];
            dq.push_front(2*x);
        }

        if(x-1>=0 && dist[x-1]>dist[x]+1){
            dist[x-1]=dist[x]+1;
            dq.push_back(x-1);
        }

        if(x+1<=MAX && dist[x+1]>dist[x]+1){
            dist[x+1]=dist[x]+1;
            dq.push_back(x+1);
        }
    }

    return 0;
}