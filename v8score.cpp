#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20 + 1;
const int MAX_S = 400 + 1;

int s, k, n, arr[MAX_N][MAX_N];

void Input() {
    cin >> s >> k >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++) cin >> arr[i][j];
}

int dp[MAX_S][MAX_N], x[MAX_N];

void Process() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) dp[arr[i][1]][1] = arr[i][1];

    for (int t = 1; t + 1 <= k; t++) for (int i = 1; i <= 200; i++) for (int x = 1; x <= n; x++) {
        if (dp[i][t] != 0 && arr[x][t + 1] >= dp[i][t]
        && (dp[i + arr[x][t + 1]][t + 1] == 0 || arr[x][t + 1] < dp[i + arr[x][t + 1]][t + 1])) {
            dp[i + arr[x][t + 1]][t + 1] = arr[x][t + 1];
        }
    }

    cout << (dp[s][k] ? "YES" : "NO") << '\n';

    if (dp[s][k] == 0) return;

    for (int i = k; i >= 1; i--) x[i] = dp[s][i], s -= dp[s][i];

    for (int i = 1; i <= k; i++) cout << x[i] << " \n"[i == k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
