#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)3e6 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int cnt, d[MAX_N];

void Process() {
    sort(arr + 1, arr + n + 1);

    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] == arr[i]) d[++cnt] = arr[i++];
    }

    if (cnt <= 1) cout << -1 << '\n';
    else cout << 1LL * d[cnt] * d[cnt - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
