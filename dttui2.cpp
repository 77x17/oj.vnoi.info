// https://oj.vnoi.info/problem/dttui2

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000 + 1;
const int MAX_M = 10000 + 1;

int n, m, w[MAX_N], v[MAX_N];

void Input() {
    cin >> n >> m;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int _w, _v, a;

        cin >> _w >> _v >> a;

        int k = 1;

        while (a >= k) {
            a -= k;

            w[++cnt] = _w * k, v[cnt] = _v * k;

            k *= 2;
        }

        if (a > 0) w[++cnt] = _w * a, v[cnt] = _v * a;
    }

    n = cnt;
}

int dp[MAX_N][MAX_M];

void Process() {
    for (int x = 0; x <= m; x++) dp[0][x] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}


