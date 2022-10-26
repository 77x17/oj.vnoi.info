#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)2e3 + 1;

string s;

void Input() {
    cin >> s;
}

int dp[MAX_N][MAX_N];

void Trace(int l, int r) {
    if (l == r) {
        cout << s[r - 1];

        return;
    }

    if (s[l - 1] == s[r - 1]) {
        cout << s[l - 1];

        Trace(l + 1, r - 1);

        cout << s[r - 1];

        return;
    }

    (dp[l][r] == dp[l + 1][r]) ? Trace(l + 1, r) : Trace(l, r - 1);
}

void Process() {
    for (int i = 1; i <= (int)s.size(); i++) dp[i][i] = 1;

    for (int i = 1; i + 1 <= (int)s.size(); i++) dp[i][i + 1] = 1 + (s[i - 1] == s[i]);

    for (int k = 3; k <= (int)s.size(); k++) {
        for (int l = 1; l + k - 1 <= (int)s.size(); l++) {
            int r = l + k - 1;

            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            if (s[l - 1] == s[r - 1]) dp[l][r] = max(dp[l][r], 2 + dp[l + 1][r - 1]);
        }
    }

    Trace(1, (int)s.size());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
