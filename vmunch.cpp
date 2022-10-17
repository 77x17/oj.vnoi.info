#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAX_N = 100 + 1;
const int INF = (int)1e9 + 7;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m;
string arr[MAX_N];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) arr[i] = ' ' + arr[i];
}

pair<int, int> s, t;
int d[MAX_N][MAX_N];

void Dfs(pair<int, int> u) {
    for (int i = 0; i < 4; i++) {
        pair<int, int> v = u;
        v.fi += dx[i], v.se += dy[i];

        if (1 <= v.fi && v.fi <= n && 1 <= v.se && v.se <= m) {
            if (arr[v.fi][v.se] != '*' && d[v.fi][v.se] > d[u.fi][u.se] + 1) {
                d[v.fi][v.se] = d[u.fi][u.se] + 1;

                Dfs(v);
            }
        }
    }
}

void Process() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (arr[i][j] == 'B') s = make_pair(i, j);
        if (arr[i][j] == 'C') t = make_pair(i, j);
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) d[i][j] = INF;

    d[s.fi][s.se] = 0;

    Dfs(s);

    cout << d[t.fi][t.se] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
