#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5;

int n, c;
vector<int> adj[MAX_N];

void Input() {
    cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        int u, v1, v2; cin >> u >> v1 >> v2;

        adj[u].push_back(v1); adj[u].push_back(v2);
    }
}

int f[MAX_N];

void Dfs(int u) {
    for (int v : adj[u]) {
        f[v] = f[u] + 1;
        Dfs(v);
    }
}

void Process() {
    f[1] = 1; Dfs(1);

    for (int i = 1; i <= n; i++) cout << f[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
