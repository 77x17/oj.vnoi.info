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

int n, k;
string s;

void Input() {
    cin >> n >> k;
    cin >> s;
}

Hash a[MAX_N];

Hash getHash(Hash arr[], int l, int r) {
    return (arr[r] - arr[l - 1]) * (n - r);
}

vector<Hash> order;

bool Matchable(int x) {
    order.clear();

    for (int i = 1; i + x - 1 <= n; i++) order.push_back(getHash(a, i, i + x - 1));

    sort(order.begin(), order.end());

    int cnt = 1;
    for (int i = 1; i < (int)order.size(); i++) {
        if (order[i] == order[i - 1]) cnt++; else cnt = 1;

        if (cnt >= k) return true;
    }

    return cnt >= k;
}

void Process() {
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + Hash(s[i - 1]) * i;

    int l = 0, r = n, result = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (Matchable(mid)) l = mid + 1, result = mid;
        else r = mid - 1;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
