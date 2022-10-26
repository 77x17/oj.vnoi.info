#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
const int MAX_M = 10000 + 1;
const int INF = (int)1e9 + 7;

int n, m, arr[MAX_M + 1], f[MAX_N][MAX_N];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> f[i][j];
}

void Process() {
    for (int i = 1; i <= n; i++) f[i][i] = INF;

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }

    for (int i = 1; i <= n; i++) f[i][i] = 0;

    long long result = 0;
    arr[0] = 1, arr[m + 1] = n;
    for (int i = 0; i <= m; i++) result += f[arr[i]][arr[i + 1]];
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
