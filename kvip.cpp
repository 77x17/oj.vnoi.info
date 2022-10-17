#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000 + 1;
const long long INF = (long long)1e18 + 7;

int n, arr[MAX_N][MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
}

long long dp[MAX_N];

void Process() {
    dp[1] = 0;
    for (int i = 1; i <= n; i++) dp[1] += arr[i][i];

    long long result = dp[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = -INF;
        for (int j = i - 1; j >= 1; j--) {
            dp[i] = max(dp[i], dp[j] - arr[j][1] + arr[j][i] - arr[i][i] + arr[i][1]);
        }

        result = max(result, dp[i]);
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
