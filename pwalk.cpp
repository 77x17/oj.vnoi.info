#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000 + 1;
const int LOG = log(MAX_N) / log(2) + 1;

#define fi first
#define se second

int n, q;
vector<pair<int, int>> adj[MAX_N];

void Input() {
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v, c; cin >> u >> v >> c;

        adj[u].emplace_back(c, v); adj[v].emplace_back(c, u);
    }
}

int dist[MAX_N], high[MAX_N], par[MAX_N][LOG + 1];

void Dfs(int u) {
    for (pair<int, int> v : adj[u]) if (v.se != par[u][0]) {
        par[v.se][0] = u;
        dist[v.se] = dist[u] + v.fi;
        high[v.se] = high[u] + 1;
        Dfs(v.se);
    }
}

int LCA(int u, int v) {
    if (high[u] < high[v]) return LCA(v, u);

    for (int j = LOG; j >= 0; j--) if (high[par[u][j]] >= high[v]) u = par[u][j];

    if (u == v) return u;

    for (int j = LOG; j >= 0; j--) if (par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];

    return par[u][0];
}

void Process() {
    fill(dist, dist + n + 1, 0); fill(high, high + n + 1, 0);
    memset(par, 0, sizeof par); high[0] = -1;

    Dfs(1);

    for (int j = 1; j <= LOG; j++) for (int i = 1; i <= n; i++) {
        par[i][j] = par[par[i][j - 1]][j - 1];
    }

    while (q--) {
        int u, v; cin >> u >> v;

        cout << dist[u] + dist[v] - 2 * dist[LCA(u, v)] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
