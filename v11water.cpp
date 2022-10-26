#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e6 + 1;

int n, h[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
}

int l[MAX_N], r[MAX_N], f[MAX_N];

void Process() {
    l[1] = h[1]; for (int i = 1 + 1; i <= n; i++) l[i] = max(l[i - 1], h[i]);
    r[n] = h[n]; for (int i = n - 1; i >= 1; i--) r[i] = max(r[i + 1], h[i]);

    for (int i = 1; i <= n; i++) f[i] = max(0, min(l[i], r[i]) - h[i]);

    long long result = 0;
    for (int i = 1; i <= n; i++) result += f[i];
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
