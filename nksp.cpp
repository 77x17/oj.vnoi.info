#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001 + 1;

string s; int n;

void Input() {
    cin >> s; n = s.size(); s = ' ' + s;
}

bool f[MAX_N][MAX_N];

void Process() {
    memset(f, false, sizeof f);

    for (int i = 1; i <= n; i++) f[i][i] = true;

    for (int i = 1; i - 1 <= n; i++) {
        if (s[i] == s[i + 1]) f[i][i + 1] = true;
    }

    for (int j = 2; j <= n; j++) {
        for (int i = 1; i + j <= n; i++) {
            if (s[i] == s[i + j]) f[i][i + j] = f[i + 1][i + j - 1];
        }
    }

    for (int i = 1; i <= n; i++) f[i][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 3; j <= n; j++) if (f[i][j] == false) {
            for (int k = i + 1; k + 1 <= j - 1; k++) {
                if (f[i][k] && f[k + 1][j]) {f[i][j] = true; break;}
            }
        }
    }

    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (f[i][j]) result++;
        }
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
