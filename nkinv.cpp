#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)6e4 + 1;

struct FenwickTree {
    int n, val[MAX_N];

    void init(int _n) {
        n = _n;
        fill(val, val + n + 1, 0);
    }

    void update(int x) {
        for (; x >= 1; x -= (x & -x)) val[x]++;
    }

    int get(int x) {
        int result = 0;
        for (; x < MAX_N; x += (x & -x)) result += val[x];
        return result;
    }
} bit;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += bit.get(arr[i] + 1);
        bit.update(arr[i]);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
