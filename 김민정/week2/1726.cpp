#include <iostream>
#include <algorithm>
using namespace std;

int maxT[200004];
int arr[50001];
int n, q;

void build(int node, int start, int end) {
    if (start == end) {
        maxT[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    maxT[node] = max(maxT[node*2], maxT[node*2+1]);
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return maxT[node];
    int mid = (start + end) / 2;
    return max(query(node*2, start, mid, l, r),
               query(node*2+1, mid+1, end, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
    }

    return 0;
}
