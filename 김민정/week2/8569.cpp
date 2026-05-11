#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, q;
int d[300001];
ll seg_sum[1200004];
int seg_cnt[1200004];
int d_val[300001];
unordered_map<int,int> d_map;
int size_;

void update(int pos, int val) {
    int node = pos + size_;
    while (node) {
        seg_cnt[node]++;
        seg_sum[node] += val;
        node >>= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> d[i];

    vector<int> sorted_d(d+1, d+n+1);
    sort(sorted_d.begin(), sorted_d.end(), greater<int>());
    sorted_d.erase(unique(sorted_d.begin(), sorted_d.end()), sorted_d.end());

    int m = sorted_d.size();
    size_ = 1;
    while (size_ < m) size_ <<= 1;

    for (int i = 0; i < (int)sorted_d.size(); i++) {
        d_val[i] = sorted_d[i];
        d_map[sorted_d[i]] = i;
    }

    vector<tuple<int,ll,int>> queries(q);
    for (int i = 0; i < q; i++) {
        int x; ll p;
        cin >> x >> p;
        queries[i] = make_tuple(x, p, i);
    }
    sort(queries.begin(), queries.end());

    vector<int> res(q);
    int idx = 1;

    for (int i = 0; i < q; i++) {
        int x = get<0>(queries[i]);
        ll p = get<1>(queries[i]);
        int qi = get<2>(queries[i]);

        while (idx <= x) {
            update(d_map[d[idx]], d[idx]);
            idx++;
        }

        int node = 1;
        ll prefix = 0;
        int cnt = 0;

        if (seg_sum[1] < p) {
            res[qi] = -1;
        } else {
            while (node < size_) {
                if (seg_sum[node*2] + prefix <= p) {
                    prefix += seg_sum[node*2];
                    cnt += seg_cnt[node*2];
                    node = node*2+1;
                } else {
                    node = node*2;
                }
            }
            ll remaining = p - prefix;
            if (remaining <= 0)
                cnt += 0;
            else
                cnt += (remaining + d_val[node - size_] - 1) / d_val[node - size_];
            res[qi] = cnt;
        }
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";

    return 0;
}
