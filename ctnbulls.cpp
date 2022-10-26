#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;
const int MOD = 2111992;

int n, k;

void Input() {
    cin >> n >> k;
}

int dp[MAX_N][2];

inline int add(const int& x, const int& y) {
    int result = x + y;
    if (result >= MOD) result -= MOD;
    return result;
}

void Process() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = add(dp[i - 1][0], dp[i - 1][1]);
        if (i - k - 1 >= 1) dp[i][1] = add(dp[i - k - 1][0], dp[i - k - 1][1]);
        else dp[i][1] = 1;
    }

    cout << add(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
