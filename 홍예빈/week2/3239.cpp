// 정올 3239번 구간의 최소값 - 세그먼트 트리
#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int N, M;

long long arr[100001];
long long minTree[400001]; // 최소값 저장
int idxTree[400001]; // 최소값의 인덱스 저장


void pull(int node){ // 부모 노드 업데이트

    int left = node * 2;
    int right = node * 2 + 1;

    if (minTree[left] < minTree[right]){
        minTree[node] = minTree[left];
        idxTree[node] = idxTree[left];
    }
    else if (minTree[left] > minTree[right]){
        minTree[node] = minTree[right];
        idxTree[node] = idxTree[right];
    }
    else { // 값이 같은 경우 인덱스가 작은 것 선택
        minTree[node] = minTree[left];
        idxTree[node] = min(idxTree[left], idxTree[right]);
    }
}

void build(int node, int start, int end){

    if (start == end){

        minTree[node] = arr[start];
        idxTree[node] = start;

        return;
    }
    int mid = (start + end) / 2;

    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    pull(node);
}


void update(int node, int start, int end, int index, long long value){
    if (index < start || index > end)
        return;

    if (start == end){
        arr[index] = value;
        minTree[node] = value;
        idxTree[node] = index;
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);

    pull(node);
}


pair<long long, int> query(int node, int start, int end, int left, int right){

    if (right < start || end < left)
        return {INF, 1e9};

    if (left <= start && end <= right)
        return {minTree[node], idxTree[node]};

    int mid = (start + end) / 2;

    auto l = query(node * 2, start, mid, left, right);
    auto r = query(node * 2 + 1, mid + 1, end, left, right);

    if (l.first < r.first)
        return l;

    if (l.first > r.first)
        return r;

    if (l.second < r.second)
        return l;

    return r;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++){ // 초기값은 전부 INF로 설정
        arr[i] = INF;
    }

    build(1, 1, N);

    while (M--){

        int cmd;
        cin >> cmd;

        if (cmd == 1){ // 1 k val : k번째 수를 val로 수정 
            int k;
            long long val;

            cin >> k >> val;

            update(1, 1, N, k, val);
        }

        else if (cmd == 2){ // 2 s e : s~e 구간에서 최소값의 인덱스 출력
            int s, e;
            cin >> s >> e;

            auto res = query(1, 1, N, s, e);

            if (res.first != INF)
                cout << res.second << '\n';
        }

        else { // 3 s e : s~e 구간에서 최소값을 INF로 수정
            int s, e;
            cin >> s >> e;

            auto res = query(1, 1, N, s, e);

            if (res.first != INF){
                update(1, 1, N, res.second, INF);
            }
        }
    }

    return 0;
}