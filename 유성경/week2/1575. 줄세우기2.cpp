#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[50005];
int min_tree[200005];
int max_tree[200005];

int getMin(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int getMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void init(int node, int start, int end)
{
    if (start == end)
    {
        min_tree[node] = arr[start];
        max_tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    min_tree[node] = getMin(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = getMax(max_tree[node * 2], max_tree[node * 2 + 1]);
}

int query_min(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 2000000000;
    }

    if (left <= start && end <= right)
    {
        return min_tree[node];
    }

    int mid = (start + end) / 2;
    return getMin(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
}

int query_max(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return -1;
    }

    if (left <= start && end <= right)
    {
        return max_tree[node];
    }

    int mid = (start + end) / 2;
    return getMax(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
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
        cin >> arr[i];
    }

    init(1, 1, N);

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        int max_val = query_max(1, 1, N, a, b);
        int min_val = query_min(1, 1, N, a, b);

        cout << max_val - min_val << "\n";
    }

    return 0;
}
#endif