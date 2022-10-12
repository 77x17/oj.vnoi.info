#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e6 + 1;

const int N_MOD = 1;
const int BASE = 256;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

int pw[MAX_N][N_MOD];

void Prepare() {
    for (int j = 0; j < N_MOD; j++) {
        pw[0][j] = 1;
        for (int i = 1; i < MAX_N; i++) pw[i][j] = 1LL * pw[i - 1][j] * BASE % MOD[j];
    }
}

struct Hash {
    int val[N_MOD];

    Hash() {fill(val, val + N_MOD, 0);}
    Hash(char c) {fill(val, val + N_MOD, c);}

    Hash operator + (const Hash& x) const {
        Hash result;
        for (int j = 0; j < N_MOD; j++) {
            if ((result.val[j] = val[j] + x.val[j]) >= MOD[j]) result.val[j] -= MOD[j];
        }
        return result;
    }

    Hash operator - (const Hash& x) const {
        Hash result;
        for (int j = 0; j < N_MOD; j++) {
            if ((result.val[j] = val[j] - x.val[j]) < 0) result.val[j] += MOD[j];
        }
        return result;
    }

    Hash operator * (const int& k) const {
        Hash result;
        for (int j = 0; j < N_MOD; j++) {
            result.val[j] = 1LL * val[j] * pw[k][j] % MOD[j];
        }
        return result;
    }

    bool operator < (const Hash& x) const {
        for (int j = 0; j < N_MOD; j++) if (val[j] != x.val[j]) return val[j] < x.val[j];
        return false;
    }

    bool operator == (const Hash& x) const {
        for (int j = 0; j < N_MOD; j++) if (val[j] != x.val[j]) return false;
        return true;
    }
};


int n, m;
string s, t;

void Input() {
    cin >> n >> m;
    cin >> s >> t;
}

Hash a[MAX_N], b[MAX_N];

Hash getHash(Hash arr[], int l, int r) {
    return (arr[r] - arr[l - 1]) * (max(n, m) - r);
}

bool Equal(int i, int j, int l) {
    return getHash(a, i, i + l - 1) == getHash(b, j, j + l - 1);
}

int Lcp(int l, int r, int u, int v) {
    if (s[l - 1] != t[u - 1]) return 0;

    int L = 0, R = min(r - l + 1, v - u + 1);

    while (true) {
        if (L == R) return R;

        if (R - L == 1) return Equal(l, u, R) ? R : L;

        int mid = (L + R) >> 1;

        if (Equal(l, u, mid)) L = mid; else R = mid - 1;
    }
}

void Process() {
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + Hash(s[i - 1]) * i;
    for (int i = 1; i <= m; i++) b[i] = b[i - 1] + Hash(t[i - 1]) * i;

    int q; cin >> q; while (q--) {
        int l, r, u, v; cin >> l >> r >> u >> v;

        int k = Lcp(l, r, u, v);

        if (k == r - l + 1) if (v - u > r - l) cout << '<'; else cout << '=';
        else if (k == v - u + 1) if (r - l > v - u) cout << '>'; else cout << '=';
        else if (s[l + k - 1] < t[u + k - 1]) cout << '<'; else cout << '>';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
