#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[100005];
int tree[400005];

void update(int node, int start, int end, int index, int diff)
{
    if (index < start || index > end)
    {
        return;
    }

    tree[node] += diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
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
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
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
        update(1, 1, 100000, arr[i], 1);
    }

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;

            int score = arr[x];
            int higher_count = query(1, 1, 100000, score + 1, 100000);

            cout << higher_count + 1 << "\n";
        }
        else if (type == 2)
        {
            int x, y;
            cin >> x >> y;

            int old_score = arr[x];
            update(1, 1, 100000, old_score, -1);

            arr[x] = y;
            update(1, 1, 100000, y, 1);
        }
    }

    return 0;
}
#endif