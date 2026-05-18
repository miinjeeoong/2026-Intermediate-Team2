#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[50005];
int max_tree[200005];

int get_max(int a, int b)
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
        max_tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);

    max_tree[node] = get_max(max_tree[node * 2], max_tree[node * 2 + 1]);
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
    return get_max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
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
        int A, B;
        cin >> A >> B;

        cout << query_max(1, 1, N, A, B) << "\n";
    }

    return 0;
}
#endif