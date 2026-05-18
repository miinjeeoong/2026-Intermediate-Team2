#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

long long D[300005];
long long vals[300005];
int vals_cnt = 0;

struct Query
{
    int x;
    long long p;
    int id;
} q_arr[300005];

long long tree_sum[1200005];
int tree_cnt[1200005];
int ans[300005];

bool cmp(const Query& a, const Query& b)
{
    return a.x < b.x;
}

int get_idx(long long val)
{
    int left = 1, right = vals_cnt;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vals[mid] == val)
        {
            return mid;
        }

        if (vals[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void update(int node, int start, int end, int idx, long long val)
{
    if (idx < start || idx > end)
    {
        return;
    }

    tree_cnt[node]++;
    tree_sum[node] += val;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
    }
}

int query(int node, int start, int end, long long p)
{
    if (start == end)
    {
        return (p + vals[start] - 1) / vals[start];
    }

    int mid = (start + end) / 2;

    if (tree_sum[node * 2 + 1] >= p)
    {
        return query(node * 2 + 1, mid + 1, end, p);
    }
    else
    {
        return tree_cnt[node * 2 + 1] + query(node * 2, start, mid, p - tree_sum[node * 2 + 1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
        vals[i] = D[i];
    }

    sort(vals + 1, vals + N + 1);
    vals_cnt = 1;

    for (int i = 2; i <= N; i++)
    {
        if (vals[i] != vals[vals_cnt])
        {
            vals[++vals_cnt] = vals[i];
        }
    }

    for (int i = 1; i <= Q; i++)
    {
        cin >> q_arr[i].x >> q_arr[i].p;
        q_arr[i].id = i;
    }

    sort(q_arr + 1, q_arr + Q + 1, cmp);

    int curr_x = 0;

    for (int i = 1; i <= Q; i++)
    {
        while (curr_x < q_arr[i].x)
        {
            curr_x++;
            int idx = get_idx(D[curr_x]);
            update(1, 1, vals_cnt, idx, D[curr_x]);
        }

        if (tree_sum[1] < q_arr[i].p)
        {
            ans[q_arr[i].id] = -1;
        }
        else
        {
            ans[q_arr[i].id] = query(1, 1, vals_cnt, q_arr[i].p);
        }
    }

    for (int i = 1; i <= Q; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
#endif