// 정올 1726번 구간의 최대값1 - 세그먼트 트리
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;

int arr[50001];
int maxTree[200001];

void build(int node, int start, int end){

    if (start == end){
        maxTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);

    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

int findMax(int node, int start, int end, int left, int right){

    if (right < start || end < left)
        return -1e9;

    if (left <= start && end <= right)
        return maxTree[node];

    int mid = (start + end) / 2;

    return max(
        findMax(node * 2, start, mid, left, right),
        findMax(node * 2 + 1, mid + 1, end, left, right)
    );
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    build(1, 1, N);

    while (Q--){

        int A, B;
        cin >> A >> B;

        cout << findMax(1, 1, N, A, B) << '\n';
    }

    return 0;
}