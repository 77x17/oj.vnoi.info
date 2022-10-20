#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 7;
const int MAX_N = (int)1e6 + 1;

struct FenwickTree {
    int n, val[MAX_N];

    void Init(int _n) {
        n = _n;

        fill(val + 1, val + _n + 1, INF);
    }

    void Update(int x, int _val) {
        for (; x <= n; x += x & -x) val[x] = min(val[x], _val);
    }

    int getMin(int x) {
        int result = INF;
        for (; x >= 1; x -= x & -x) result = min(result, val[x]);
        return result;
    }
} bit;

struct score {
    int a, b, c;

    bool operator < (const score& x) {return a < x.a;}
};

int n;
score arr[MAX_N];

void Input() {
    cin >> n;

    int x;
    for (int i = 1; i <= n; i++) {cin >> x; arr[x].a = i;}
    for (int i = 1; i <= n; i++) {cin >> x; arr[x].b = i;}
    for (int i = 1; i <= n; i++) {cin >> x; arr[x].c = i;}
}

void Process() {
    sort(arr + 1, arr + n + 1);

    bit.Init(n);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (bit.getMin(arr[i].b) > arr[i].c) result++;

        bit.Update(arr[i].b, arr[i].c);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
