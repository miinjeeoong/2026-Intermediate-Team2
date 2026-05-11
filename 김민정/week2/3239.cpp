#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 2e9;

pair<int,int> tree[400004];
int arr[100001];
int n, m;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {arr[start], start};
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = {val, idx};
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(node*2, start, mid, idx, val);
    else update(node*2+1, mid+1, end, idx, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

pair<int,int> query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return {INF, INF};
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return min(query(node*2, start, mid, l, r),
               query(node*2+1, mid+1, end, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        arr[i] = INF;

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int k, val;
            cin >> k >> val;
            update(1, 1, n, k, val);
        } else if (cmd == 2) {
            int s, e;
            cin >> s >> e;
            pair<int,int> res = query(1, 1, n, s, e);
            if (res.first != INF)
                cout << res.second << "\n";
        } else {
            int s, e;
            cin >> s >> e;
            pair<int,int> res = query(1, 1, n, s, e);
            if (res.first != INF)
                update(1, 1, n, res.second, INF);
        }
    }

    return 0;
}
