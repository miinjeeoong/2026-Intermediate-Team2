#include <iostream>
#include <algorithm>
using namespace std;

int maxT[200004], minT[200004];
int arr[50001];
int n, q;

void build(int node, int start, int end) {
    if (start == end) {
        maxT[node] = arr[start];
        minT[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    maxT[node] = max(maxT[node*2], maxT[node*2+1]);
    minT[node] = min(minT[node*2], minT[node*2+1]);
}

int queryMax(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return maxT[node];
    int mid = (start + end) / 2;
    return max(queryMax(node*2, start, mid, l, r),
               queryMax(node*2+1, mid+1, end, l, r));
}

int queryMin(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 1000001;
    if (l <= start && end <= r) return minT[node];
    int mid = (start + end) / 2;
    return min(queryMin(node*2, start, mid, l, r),
               queryMin(node*2+1, mid+1, end, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int mx = queryMax(1, 1, n, a, b);
        int mn = queryMin(1, 1, n, a, b);
        cout << mx - mn << "\n";
    }

    return 0;
}
