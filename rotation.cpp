#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e3 + 1;

int n;
vector<pair<int, int>> adj[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, d, c; cin >> s >> d >> c;
        adj[s].emplace_back(c, d);
    }
}

int f[MAX_N];

void Dfs(int u) {
    for (pair<int, int> v : adj[u]) {
        f[v.second] = f[u] ^ v.first;

        Dfs(v.second);
    }
}

void Process() {
    f[1] = 0;

    Dfs(1);

    cout << f[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
