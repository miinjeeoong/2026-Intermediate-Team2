// 정올 1575번 줄세우기2 - 세그먼트 트리
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;

int arr[50001];

int minTree[200001];
int maxTree[200001];

void build(int node, int start, int end){

    if (start == end){
        minTree[node] = arr[start];
        maxTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);

    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

int findMin(int node, int start, int end, int left, int right){

    if (right < start || end < left)
        return 1e9;

    if (left <= start && end <= right)
        return minTree[node];

    int mid = (start + end) / 2;

    return min(
        findMin(node * 2, start, mid, left, right),
        findMin(node * 2 + 1, mid + 1, end, left, right)
    );
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

    cin >> N >> Q;

    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    build(1, 1, N);

    while (Q--){

        int A, B;
        cin >> A >> B;

        int mn = findMin(1, 1, N, A, B);
        int mx = findMax(1, 1, N, A, B);

        cout << mx - mn << '\n';
    }

    return 0;
}