#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)25e3 + 1;

int n, f[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i < n; i++) cin >> f[i];
}

int dp[MAX_N];

void Process() {
    dp[1] = f[1];
    dp[2] = f[1] + f[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + f[i];
    }
    cout << dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
