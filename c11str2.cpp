#include <bits/stdc++.h>
using namespace std;

const int N_MOD = 4;
const int BASE = 256;
const int MAX_N = (int)1e5 + 1;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

int pw[N_MOD][MAX_N];

void Prepare() {
    for (int i = 0; i < N_MOD; i++) {
        pw[i][0] = 1;

        for (int j = 1; j < MAX_N; j++) pw[i][j] = 1LL * pw[i][j - 1] * BASE % MOD[i];
    }
}

struct Hash {
    int val[N_MOD];

    Hash() {fill(val, val + N_MOD, 0);}
    Hash(char c) {fill(val, val + N_MOD, c);}

    Hash operator + (const Hash& x) const {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = val[i] + x.val[i];

            if (result.val[i] >= MOD[i]) result.val[i] -= MOD[i];
        }
        return result;
    }

    Hash operator - (const Hash& x) const {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = val[i] - x.val[i];

            if (result.val[i] < 0) result.val[i] += MOD[i];
        }
        return result;
    }

    Hash operator * (const int& k) const {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = 1LL * val[i] * pw[i][k] % MOD[i];
        }
        return result;
    }

    bool operator < (const Hash& x) const {
        for (int i = 0; i < N_MOD; i++) if (val[i] != x.val[i]) return val[i] < x.val[i];
        return false;
    }

    bool operator == (const Hash& x) const {
        for (int i = 0; i < N_MOD; i++) if (val[i] != x.val[i]) return false;
        return true;
    }
};

string a, b; int n, m;

void Input() {
    cin >> a >> b; n = a.size(), m = b.size();
}

int N;
Hash s[MAX_N], t[MAX_N];

Hash getHash(int l, int r, Hash arr[]) {
    return (arr[r] - arr[l - 1]) * (N - r);
}

void Process() {
    N = max(n, m);

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + Hash(a[i - 1]) * i;
    for (int i = 1; i <= m; i++) t[i] = t[i - 1] + Hash(b[i - 1]) * i;

    m = min(n, m);

    for (int i = m; i >= 1; i--) {
        if (getHash(1, i, t) == getHash(n - i + 1, n, s)) {
            cout << a.substr(0, n - i) << b << '\n';

            return;
        }
    }

    cout << a << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
