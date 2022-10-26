#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)6e4 + 1;

int n, t[MAX_N], r[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <  n; i++) cin >> r[i];
}

long long dp[MAX_N];

void Process() {
    dp[1] = t[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
    }
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
