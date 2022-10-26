#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50000 + 1;

int n, m, k, a[MAX_N], b[MAX_N];

void Input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
}

struct Comp {
    bool operator () (pair<int, int> x, pair<int, int> y) {
        return a[x.first] + b[x.second] > a[y.first] + b[y.second];
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

void Process() {
    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++) pq.emplace(i, 1);

    for (int i = 1; i <= k; i++) {
        cout << a[pq.top().first] + b[pq.top().second] << '\n';

        pair<int, int> x = pq.top(); pq.pop();

        if (x.second + 1 <= m) pq.emplace(x.first, x.second + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
