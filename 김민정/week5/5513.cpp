#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    long long dp[31][31][2][2] = {};

    dp[0][0][0][0] = 1;

    for (int pos = 1; pos <= N; pos++) {
        for (int cnt = 0; cnt <= K; cnt++) {
            for (int a = 0; a <= 1; a++) {
                for (int b = 0; b <= 1; b++) {
                    long long cur = dp[pos - 1][cnt][a][b];
                    if (cur == 0) continue;

                    for (int x = 0; x <= 1; x++) {
                        if (cnt + x > K) continue;

                        bool ok = true;

                        if (pos >= 2 && b == 1) {
                            bool leftEmpty = (pos >= 3 && a == 0);
                            bool rightEmpty = (x == 0);

                            if (!leftEmpty && !rightEmpty) {
                                ok = false;
                            }
                        }

                        if (ok) {
                            dp[pos][cnt + x][b][x] += cur;
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            if (b == 1) {
                bool leftEmpty = (N >= 2 && a == 0);
                if (!leftEmpty) continue;
            }

            ans += dp[N][K][a][b];
        }
    }

    cout << ans << '\n';

    return 0;
}
