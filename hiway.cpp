// https://oj.vnoi.info/problem/hiway

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int max_n = 100 + 1;

struct minCostFlow {
    struct Edge {
        int from, to, capa, cost, flow;

        Edge (int _from = 0, int _to = 0, int _capa = 0, int _cost = 0) {
            from = _from, to = _to, capa = _capa, cost = _cost, flow = 0;
        }

        int residual() {return capa - flow;}
    };

    vector<Edge> edges; vector<int> adj[max_n];

    void addEdge(int u, int v, int c, int w) {
        adj[u].push_back(edges.size()); edges.push_back(Edge(u, v, c, +w));
        adj[v].push_back(edges.size()); edges.push_back(Edge(v, u, 0, -w));
    }

    bool in_queue[max_n];
    int d[max_n], par[max_n];

    bool findAugmentPath(int s, int t) {
        fill(in_queue, in_queue + max_n, false);
        fill(d, d + max_n, inf); fill(par, par + max_n, -1);

        queue<int> q; q.push(s); d[s] = 0; in_queue[s] = true;

        while (q.size()) {
            int u = q.front(); q.pop(); in_queue[u] = false;

            for (int x : adj[u]) if (edges[x].residual()) {
                int v = edges[x].to, w = edges[x].cost;

                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w; par[v] = x;

                    if (not in_queue[v]) in_queue[v] = true, q.push(v);
                }
            }
        }

        return (d[t] != inf);
    }

    pair<int, int> maxFlow_minCost(int s, int t) {
        int maxFlow = 0, minCost = 0;

        while (findAugmentPath(s, t)) {
            int delta = inf;

            for (int x = t; x != s; x = edges[par[x]].from) {
                delta = min(delta, edges[par[x]].residual());
            }

            for (int x = t; x != s; x = edges[par[x]].from) {
                edges[par[x]].flow += delta;
                edges[par[x] ^ 1].flow -= delta;
            }

            maxFlow += delta; minCost += delta * d[t];
        }

        return {maxFlow, minCost};
    }

    vector<int> order[max_n];

    void printRoads(int s, int t) {
        for (Edge x : edges) if (x.flow > 0 && x.from > 0) order[x.from].push_back(x.to);

        for (int i = 1; i <= 2; i++) {
            vector<int> result;

            int u = s; while (u != t) {
                result.push_back(u);

                int temp = order[u].back(); order[u].pop_back();

                u = temp;
            }

            result.push_back(t);

            cout << result.size() << ' '; for (int x : result) cout << x << ' '; cout << '\n';
        }
    }
} mcf;

int n, m, s, f;

void Input() {
    cin >> n >> m >> s >> f;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;

        mcf.addEdge(u, v, 1, w); mcf.addEdge(v, u, 1, w);
    }

    mcf.addEdge(0, s, 2, 0);
}

void Process() {
    pair<int, int> result = mcf.maxFlow_minCost(0, f);

    if (result.first < 2) {cout << -1 << '\n'; return;}

    cout << result.second << '\n';

    mcf.printRoads(s, f);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
