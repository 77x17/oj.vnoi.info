#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e6;

int n, f[MAX_N + 1];

void Prepare() {
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (i & 1) f[i] = f[i / 2] + f[i / 2 + 1];
        else f[i] = f[i / 2];
    }

    for (int i = 1; i <= MAX_N; i++) f[i] = max(f[i], f[i - 1]);
}

void Input() {
    cin >> n;
}

void Process() {
    cout << f[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Prepare();

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
