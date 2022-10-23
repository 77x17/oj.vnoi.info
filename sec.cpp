#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)5e4 + 1;

const int N_MOD = 4;
const int BASE = 256;
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

    Hash() {memset(val, 0, sizeof val);}
    Hash(char x) {fill(val, val + N_MOD, x);}

    Hash operator + (const Hash& x) {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = val[i] + x.val[i];
            if (result.val[i] >= MOD[i]) result.val[i] -= MOD[i];
        }
        return result;
    }

    Hash operator - (const Hash& x) {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = val[i] - x.val[i];
            if (result.val[i] < 0) result.val[i] += MOD[i];
        }
        return result;
    }

    Hash operator * (const int& k) {
        Hash result;
        for (int i = 0; i < N_MOD; i++) {
            result.val[i] = 1LL * val[i] * pw[i][k] % MOD[i];
        }
        return result;
    }

    bool operator == (const Hash& x) {
        for (int i = 0; i < N_MOD; i++) if (val[i] != x.val[i]) return false;
        return true;
    }
};

int n, m, N = 0;
string b[MAX_N], c[MAX_N];

void Input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int sz; cin >> sz; N = max(N, sz);
        for (int j = 1; j <= sz; j++) {
            char x; cin >> x; b[i] = b[i] + x;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz; N = max(N, sz);
        for (int j = 1; j <= sz; j++) {
            char x; cin >> x; c[i] = c[i] + x;
        }
    }
}

vector<Hash> s[MAX_N], t[MAX_N];

Hash getHash(int l, int r, vector<Hash> arr) {
    return (arr[r] - arr[l - 1]) * (N - r);
}

set<pair<int, int>> f[MAX_N];

void Process() {
    for (int i = 1; i <= m; i++) {
        int sz = (int)b[i].size();

        s[i].push_back(Hash());

        for (int j = 1; j <= sz; j++) {
            Hash temp = s[i][j - 1] + Hash(b[i][j - 1]) * j;
            s[i].push_back(temp);
        }
    }

    for (int i = 1; i <= n; i++) {
        int sz = (int)c[i].size();

        t[i].push_back(Hash());

        for (int j = 1; j <= sz; j++) {
            Hash temp = t[i][j - 1] + Hash(c[i][j - 1]) * j;
            t[i].push_back(temp);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if ((int)c[i].size() <= (int)b[j].size()) {
            if (getHash(1, (int)c[i].size(), t[i]) == getHash(1, (int)c[i].size(), s[j])) f[i].emplace(i, j);
        }

        for (int j = 1; j <= m; j++) if ((int)c[i].size() >= (int)b[j].size()) {
            if (getHash(1, (int)b[j].size(), t[i]) == getHash(1, (int)b[j].size(), s[j])) f[i].emplace(i, j);
        }
    }

    for (int i = 1; i <= n; i++) cout << (int)f[i].size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
