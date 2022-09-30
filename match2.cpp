//https://oj.vnoi.info/problem/match2

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 1000 + 1;

struct minCostFlow {
    struct Edge {
        int from, to, capa, cost, flow;

        Edge (int _from = 0, int _to = 0, int _capa = 0, int _cost = 0) {
            from = _from, to = _to, capa = _capa, cost = _cost, flow = 0;
        }

        int remain() {return capa - flow;}
    };

    vector<Edge> edges; vector<int> adj[MAX_N];

    void addEdge(int u, int v, int c, int w) {
        adj[u].push_back(edges.size()); edges.push_back({u, v, c, +w});
        adj[v].push_back(edges.size()); edges.push_back({v, u, 0, -w});
    }

    bool in_queue[MAX_N];
    int d[MAX_N], par[MAX_N];

    bool findPath(int s, int t) {
        fill(in_queue, in_queue + MAX_N, false);
        fill(d, d + MAX_N, INF); fill(par, par + MAX_N, -1);

        queue<int> q; q.push(s); d[s] = 0; in_queue[s] = true;

        while (q.size()) {
            int u = q.front(); q.pop(); in_queue[u] = false;

            for (int x : adj[u]) if (edges[x].remain()) {
                int v = edges[x].to, w = edges[x].cost;

                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w; par[v] = x;

                    if (not in_queue[v]) q.push(v), in_queue[v] = true;
                }
            }
        }

        return d[t] != INF;
    }

    array<int, 2> maxFlow_minCost(int s, int t) {
        int maxFlow = 0, minCost = 0;

        while (findPath(s, t)) {
            int delta = INF;

            for (int x = t; x != s; x = edges[par[x]].from) {
                delta = min(delta, edges[par[x]].remain());
            }

            for (int x = t; x != s; x = edges[par[x]].from) {
                edges[par[x]].flow += delta;
                edges[par[x] ^ 1].flow -= delta;
            }

            maxFlow += delta;
            minCost += delta * d[t];
        }

        return {maxFlow, minCost};
    }

    void printEdges(int n) {
        for (Edge x : edges) if (x.from >= 1 && x.to <= n + n) {
            if (x.capa > 0 && x.flow > 0) cout << x.from << ' ' << x.to - n << '\n';
        }
    }
} mcf;

int n;

void Input() {
    cin >> n;

    int u, v, w; while (cin >> u >> v >> w) mcf.addEdge(u, v + n, 1, w);

    for (int i = 1; i <= n; i++) mcf.addEdge(0, i, 1, 0), mcf.addEdge(i + n, n + n + 1, 1, 0);
}

void Process() {
    cout << mcf.maxFlow_minCost(0, n + n + 1)[1] << '\n';

    mcf.printEdges(n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
