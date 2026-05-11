// 정올 8569번 건초 더미 - 세그먼트 트리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
long long D[300001];
long long tree[1200001];

void build(int node, int start, int end){
    if (start == end){
        tree[node] = D[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


long long query(int node, int start, int end, int left, int right){
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++){
        cin >> D[i];
    }

    build(1, 1, N);

    while (Q--){
        int X;
        long long P;

        cin >> X >> P;

        if (query(1, 1, N, 1, X) < P){

            cout << -1 << '\n';

            continue;
        }

        vector<long long> v;

        for (int i = 1; i <= X; i++){
            v.push_back(D[i]);
        }
        sort(v.begin(), v.end(), greater<long long>());

        long long sum = 0;
        int cnt = 0;

        for (long long x : v){
            sum += x;
            cnt++;

            if (sum >= P)
                break;
        }
        cout << cnt << '\n';
    }

    return 0;
}