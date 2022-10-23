#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e3 + 1;

int n;
char arr[MAX_N][MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
}

int f[MAX_N];

int Comp(const int& x, const int& y) {
    return arr[x][y] - '0';
}

void Process() {
    for (int i = 1; i <= n; i++) f[i] = i;

    sort(f + 1, f + n + 1, Comp);

    for (int i = 2; i <= n; i++) if (arr[f[i - 1]][f[i]] == '0') {
        cout << -1 << '\n';

        return;
    }

    for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
