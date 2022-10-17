#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10 + 1;
const int MAX_M = (int)1e6 + 1;

int m, n, s, a[MAX_N], b[MAX_N];

void Input() {
    cin >> m >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
}

int d[MAX_M];

void Process() {
    memset(d, -1, sizeof d);

    queue<int> q; q.push(s); d[s] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();

        for (int i = 1; i <= n; i++) {
            int v = (1LL * u * a[i] + b[i]) % m;

            if (d[v] < 0) d[v] = d[u] + 1, q.push(v);
        }
    }

    cout << d[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
