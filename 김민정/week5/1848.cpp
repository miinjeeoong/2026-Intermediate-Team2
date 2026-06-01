#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> vip(M);
    for (int i = 0; i < M; i++) {
        cin >> vip[i];
    }

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int answer = 1;
    int prev = 0;

    for (int i = 0; i < M; i++) {
        int len = vip[i] - prev - 1;
        answer *= dp[len];
        prev = vip[i];
    }

    int len = N - prev;
    answer *= dp[len];

    cout << answer << '\n';

    return 0;
}
