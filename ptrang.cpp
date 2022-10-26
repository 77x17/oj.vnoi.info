#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 6000 + 1;
const int INF = (int)1e9 + 7;

int n, k, w[MAX_N];

void Input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i];
}

int dp[MAX_N];

void Process() {
    w[0] = dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        w[i] += w[i - 1];

        dp[i] = INF;
        for (int j = i; j >= 0 && w[i] - w[j] <= k; j--) {
            dp[i] = min(dp[i], max(dp[j], k - (w[i] - w[j])));
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
