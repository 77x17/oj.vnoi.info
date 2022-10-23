#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e3 + 1;

struct edge {
    int u, v, c;

    edge(int _u = 0, int _v = 0, int _c = 0) {
        u = _u, v = _v, c = _c;
    }

    bool operator < (const edge& x) const {
        return c < x.c;
    }
};

struct DisjointSet {
    int par[MAX_N];

    void Init(int n) {
        fill(par + 1, par + n + 1, -1);
    }

    int findRoot(int x) {
        if (par[x] < 0) return x;
        return par[x] = findRoot(par[x]);
    }

    bool Union(int x, int y) {
        if ((x = findRoot(x)) == (y = findRoot(y))) return false;

        if (par[x] > par[y]) swap(x, y);

        par[x] += par[y];
        par[y] = x;

        return true;
    }
} dsu;

int n, m;
vector<edge> edges;

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;

        edges.push_back(edge(u, v, c));
    }
}

void Process() {
    sort(edges.begin(), edges.end());

    dsu.Init(n);

    int result = 0;
    for (edge x : edges) if (dsu.Union(x.u, x.v)) result = max(result, x.c);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
