#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4096;
const int INF = (int)1e9 + 7;

struct MaxFlow {
    struct edge {
        int from, to, capa, flow;

        edge(int _from, int _to, int _capa) {
            from = _from, to = _to, capa = _capa, flow = 0;
        }

        int residual() {return capa - flow;}
    };

    vector<edge> edges;
    vector<int> adj[MAX_N];

    int n;

    void Init(int _n) {
        n = _n;
        edges.clear();
        for (int i = 0; i <= _n; i++) adj[i].clear();
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back(edges.size()); edges.push_back({u, v, c});
        adj[v].push_back(edges.size()); edges.push_back({v, u, 0});
    }

    int d[MAX_N], par[MAX_N];

    bool findPath(int s, int t) {
        fill(d, d + n + 1, -1); fill(par, par + n + 1, -1);

        queue<int> q; q.push(s); d[s] = 0;

        while (q.size()) {
            int u = q.front(); q.pop();

            for (int x : adj[u]) if (edges[x].residual() > 0) {
                int v = edges[x].to;

                if (d[v] < 0) {
                    d[v] = d[u] + 1; par[v] = x;

                    q.push(v);
                }
            }
        }

        return d[t] >= 0;
    }

    int Process(int s, int t) {
        int maxFlow = 0;

        while (findPath(s, t)) {
            int delta = INF;

            for (int x = t; x != s; x = edges[par[x]].from) {
                delta = min(delta, edges[par[x]].residual());
            }

            for (int x = t; x != s; x = edges[par[x]].from) {
                edges[par[x]].flow += delta;
                edges[par[x] ^ 1].flow -= delta;
            }

            maxFlow += delta;
        }

        return maxFlow;
    }
} mcmf;

int n, x[MAX_N], y[MAX_N];

void Input() {
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
}

void Process() {
    mcmf.Init(n + n + 1);

    for (int i = 1; i <= n; i++) {
        mcmf.addEdge(0, i, 1);
        mcmf.addEdge(i + n, n + n + 1, 1);
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) {
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1) mcmf.addEdge(i, j + n, 1);
    }

    cout << n - mcmf.Process(0, n + n + 1) / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (cin >> n) {
        Input();

        Process();
    }

    return 0;
}
