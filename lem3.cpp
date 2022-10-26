#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 16 + 1;
const int INF = (int)1e9 + 7;

int n, c[MAX_N][MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> c[i][j];
}

int dp[MAX_N][1 << (MAX_N - 1)];

void Process() {
    for (int state = 0; state < (1 << n); state++) {
        for (int i = 0; i <= n; i++) dp[i][state] = INF;
    }

    for (int i = 1; i <= n; i++) dp[i][1 << (i - 1)] = 0;

    for (int state = 1; state < (1 << n); state++) {
        for (int i = 1; i <= n; i++) if (state & (1 << (i - 1))) {
            for (int j = 1; j <= n; j++) if (state & (1 << (j - 1)) && i != j) {
                dp[i][state] = min(dp[i][state], dp[j][state ^ (1 << (i - 1))] + c[i][j]);
            }
        }
    }

    int result = INF;
    for (int i = 1; i <= n; i++) result = min(result, dp[i][(1 << n) - 1]);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
