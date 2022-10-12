#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)5e4 + 1;

const int N_MOD = 4;
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

int n;
string s;

void Input() {
    cin >> n >> s;
}

Hash a[MAX_N], b[MAX_N];

Hash getHash(Hash arr[], int l, int r) {
    return (arr[r] - arr[l - 1]) * (n - r);
}

bool Matchable(int x) {
    for (int i = 1; i + x - 1 <= n; i++) {
        int j = i + x - 1;

        if (getHash(a, i, j) == getHash(b, n - j + 1, n - i + 1)) return true;
    }
    return false;
}

void Process() {
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + Hash(s[i - 1]) * i;
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + Hash(s[n - i]) * i;

    int result[2] = {-1, -1};

    int l = 0, r = n / 2;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (Matchable(2 * mid)) l = mid + 1, result[0] = 2 * mid;
        else r = mid - 1;
    }

    l = 1, r = (n + 1) / 2;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (Matchable(2 * mid - 1)) l = mid + 1, result[1] = 2 * mid - 1;
        else r = mid - 1;
    }

    cout << max(result[0], result[1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
