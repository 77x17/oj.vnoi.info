#include <bits/stdc++.h>
using namespace std;

const int MAX_M = (int)3e4;
const int MAX_N = (int)1e4 + 1;

struct FenwickTree {
    int val[MAX_M];

    void update(int x, int _val) {
        for (; x <= MAX_M; x += (x & -x)) val[x] = max(val[x], _val);
    }

    int get_max(int x) {
        int result = 0;
        for (; x >= 1; x -= (x & -x)) result = max(result, val[x]);
        return result;
    }
} BIT;

int n;
vector<pair<int, int>> arr;

void Input() {
    cin >> n; arr.emplace_back(0, 0);
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        arr.emplace_back(l, r);
    }
}

void Process() {
    sort(arr.begin() + 1, arr.end());

    for (int i = 1; i <= n; i++) {
        BIT.update(arr[i].second, BIT.get_max(arr[i].first) + arr[i].second - arr[i].first);
    }

    cout << BIT.get_max(MAX_M) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
