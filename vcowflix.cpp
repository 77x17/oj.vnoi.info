#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 16 + 1;
const int MAX_C = (int)5e3 + 1;

int c, n, w[MAX_N];

void Input() {
    cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
}

int dp[MAX_N][MAX_C];

void Process() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= c; j++) {
        dp[i][j] = dp[i - 1][j];

        if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
    }
    cout << dp[n][c] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
