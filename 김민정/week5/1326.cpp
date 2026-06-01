#include <bits/stdc++.h>
using namespace std;

struct Player {
    double acc;
    int team;
    int denom;
    vector<int> passTo;
    vector<int> stealBy;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, T;
    cin >> N >> R >> T;

    int M = 2 * N;
    vector<Player> p(M);

    for (int team = 0; team < 2; team++) {
        for (int i = 0; i < N; i++) {
            int idx = team * N + i;

            int nF, nE;
            cin >> p[idx].acc >> nF >> nE;

            p[idx].team = team;
            p[idx].denom = nF + nE + 1;

            for (int j = 0; j < nF; j++) {
                int x;
                cin >> x;
                --x;
                p[idx].passTo.push_back(team * N + x);
            }

            for (int j = 0; j < nE; j++) {
                int x;
                cin >> x;
                --x;
                p[idx].stealBy.push_back((1 - team) * N + x);
            }
        }
    }

    vector<vector<array<double, 4>>> eventProb(
        2, vector<array<double, 4>>(T + 1)
    );

    vector<vector<double>> noShot(2, vector<double>(T + 1, 0.0));

    for (int start = 0; start < 2; start++) {
        vector<double> cur(M, 0.0), nxt(M, 0.0);

        cur[start * N] = 1.0;
        noShot[start][0] = 1.0;

        for (int sec = 1; sec <= T; sec++) {
            fill(nxt.begin(), nxt.end(), 0.0);

            array<double, 4> ev{};
            ev.fill(0.0);

            for (int i = 0; i < M; i++) {
                double prob = cur[i];
                if (prob == 0.0) continue;

                double unit = prob / p[i].denom;
                int team = p[i].team;

                double goal = unit * p[i].acc;
                double miss = unit * (1.0 - p[i].acc);

                if (team == 0) {
                    ev[0] += miss;
                    ev[1] += goal;
                } else {
                    ev[2] += miss;
                    ev[3] += goal;
                }

                for (int to : p[i].passTo) {
                    nxt[to] += unit;
                }

                for (int to : p[i].stealBy) {
                    nxt[to] += unit;
                }
            }

            eventProb[start][sec] = ev;

            double sum = 0.0;
            for (double x : nxt) {
                sum += x;
            }
            noShot[start][sec] = sum;

            cur.swap(nxt);
        }
    }

    auto scoreId = [&](int a, int b) {
        return a * R + b;
    };

    vector<vector<vector<double>>> dp(
        T + 1, vector<vector<double>>(R * R, vector<double>(2, 0.0))
    );

    vector<vector<double>> ans(R + 1, vector<double>(R + 1, 0.0));

    dp[0][scoreId(0, 0)][0] = 1.0;

    for (int time = 0; time <= T; time++) {
        for (int s1 = 0; s1 < R; s1++) {
            for (int s2 = 0; s2 < R; s2++) {
                int sid = scoreId(s1, s2);

                for (int start = 0; start < 2; start++) {
                    double curProb = dp[time][sid][start];
                    if (curProb == 0.0) continue;

                    int remain = T - time;

                    ans[s1][s2] += curProb * noShot[start][remain];

                    for (int k = 1; k <= remain; k++) {
                        const auto &ev = eventProb[start][k];
                        int nt = time + k;

                        if (ev[0] != 0.0) {
                            dp[nt][sid][1] += curProb * ev[0];
                        }

                        if (ev[1] != 0.0) {
                            double add = curProb * ev[1];

                            if (s1 + 1 == R) {
                                ans[R][s2] += add;
                            } else {
                                dp[nt][scoreId(s1 + 1, s2)][1] += add;
                            }
                        }

                        if (ev[2] != 0.0) {
                            dp[nt][sid][0] += curProb * ev[2];
                        }

                        if (ev[3] != 0.0) {
                            double add = curProb * ev[3];

                            if (s2 + 1 == R) {
                                ans[s1][R] += add;
                            } else {
                                dp[nt][scoreId(s1, s2 + 1)][0] += add;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(10);

    for (int s1 = 0; s1 <= R; s1++) {
        for (int s2 = 0; s2 <= R; s2++) {
            if (s1 == R && s2 == R) continue;
            cout << ans[s1][s2] << '\n';
        }
    }

    return 0;
}
