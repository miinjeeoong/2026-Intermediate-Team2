#include <iostream>
using namespace std;

int tree[400004];
int arr[100001];
int n, q;

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(node*2, start, mid, idx, val);
    else update(node*2+1, mid+1, end, idx, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(node*2, start, mid, l, r) +
           query(node*2+1, mid+1, end, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(1, 1, 100000, arr[i], 1);
    }

    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            int score = arr[x];
            int rank = query(1, 1, 100000, score+1, 100000) + 1;
            cout << rank << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            update(1, 1, 100000, arr[x], -1);
            arr[x] = y;
            update(1, 1, 100000, arr[x], 1);
        }
    }

    return 0;
}
