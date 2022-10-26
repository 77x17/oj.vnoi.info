#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300 + 1;

struct DisjointSet {
    int par[MAX_N];

    void init(int n) {
        fill(par, par + n + 1, -1);
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

int n, w[MAX_N], p[MAX_N][MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> p[i][j];
}

struct edge {
    int u, v, c;

    edge(int _u = 0, int _v = 0, int _c = 0) {
        u = _u, v = _v, c = _c;
    }

    bool operator < (const edge& x) const {
        return c < x.c;
    }
};

vector<edge> edges;

void Process() {
    for (int i = 1; i <= n; i++) edges.push_back(edge(0, i, w[i]));

    for (int i = 1; i + 1 <= n; i++) for (int j = i + 1; j <= n; j++) edges.push_back(edge(i, j, p[i][j]));

    sort(edges.begin(), edges.end());

    dsu.init(n);

    int result = 0;
    for (edge x : edges) if (dsu.Union(x.u, x.v)) result += x.c;
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
