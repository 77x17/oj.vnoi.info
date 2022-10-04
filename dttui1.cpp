// https://oj.vnoi.info/problem/dttui1

#include <bits/stdc++.h>
using namespace std;

#define w first
#define v second
#define int32 unsigned int

const int MAX_N = 40 + 1;

int m, s, t; pair<int32, int32> a[MAX_N], b[MAX_N];

void Input() {
    int n; cin >> n >> m; s = (n + 1) / 2, t = n - s;

    for (int i = 1; i <= s; i++) cin >> a[i].w >> a[i].v;
    for (int i = 1; i <= t; i++) cin >> b[i].w >> b[i].v;
}

void operator += (pair<int32, int32>& x, pair<int32, int32> y) {x.w += y.w, x.v += y.v;}

// divideAndConquer
vector<pair<int32, int32>> Calc(const pair<int32, int32> arr[], int32 n) {
    vector<pair<int32, int32>> result;

    for (int mask = 0; mask < (1 << n); mask++) {
        pair<int32, int32> curr;

        for (int i = 1; i <= n; i++) if (mask & (1 << (i - 1))) curr += arr[i];

        if (curr.w <= m) result.push_back(curr);
    }

    sort(result.begin(), result.end());

    return result;
}

void Process() {
    vector<pair<int32, int32>> f, g;

    if (s) f = Calc(a, s); if (t) g = Calc(b, t);

    int32 result = 0, curr = 0;

    for (int i = f.size() - 1, j = 0; i >= 0; i--) {
        while (j < g.size() && f[i].w + g[j].w <= m) curr = max(curr, g[j++].v);

        result = max(result, curr + f[i].v);
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
