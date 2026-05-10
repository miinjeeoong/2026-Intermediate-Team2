#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long arr[100005];
int tree[400005];

int get_min_idx(int idx1, int idx2)
{
    if (idx1 == 0)
    {
        return idx2;
    }

    if (idx2 == 0)
    {
        return idx1;
    }

    if (arr[idx1] < arr[idx2])
    {
        return idx1;
    }

    if (arr[idx1] > arr[idx2])
    {
        return idx2;
    }

    if (idx1 < idx2)
    {
        return idx1;
    }

    return idx2;
}

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = start;
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    tree[node] = get_min_idx(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int index, long long val)
{
    if (index < start || index > end)
    {
        return;
    }

    if (start == end)
    {
        arr[index] = val;
        tree[node] = index;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, val);
    update(node * 2 + 1, mid + 1, end, index, val);

    tree[node] = get_min_idx(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return get_min_idx(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        arr[i] = 2000000000000LL;
    }

    init(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int k;
            long long val;
            cin >> k >> val;
            update(1, 1, N, k, val);
        }
        else if (cmd == 2)
        {
            int s, e;
            cin >> s >> e;
            int ans = query(1, 1, N, s, e);

            if (ans != 0 && arr[ans] != 2000000000000LL)
            {
                cout << ans << "\n";
            }
        }
        else if (cmd == 3)
        {
            int s, e;
            cin >> s >> e;
            int ans = query(1, 1, N, s, e);

            if (ans != 0 && arr[ans] != 2000000000000LL)
            {
                update(1, 1, N, ans, 2000000000000LL);
            }
        }
    }

    return 0;
}
#endif