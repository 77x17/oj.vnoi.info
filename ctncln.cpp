// https://oj.vnoi.info/problem/ctncln

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 40000 + 1;

int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int dp[MAX_N];
map<int, int> f[MAX_N];

void Process() {
    dp[0] = 0;

    do {
        set<int> s;

        for (int i = 1; i <= n; i++) s.insert(arr[i]), dp[i] = min(i, (int)(s.size() * s.size()));
    } while (false);

    for (int i = 1; i <= n; i++) {
        set<int> s;

        for (int j = i; j <= n; j++) s.insert(arr[j]), f[i][j] = s.size() * s.size();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            dp[i] = min(dp[i], dp[j] + f[j + 1][i]);
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
