#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 1;
const int INF = (int)1e9 + 7;

int n, f[MAX_N][MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> f[i][j];
}

bool visited[MAX_N];

void Process() {
    int result = 0;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (f[i][j] == 0) f[i][j] = INF;

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
    }

    fill(visited + 1, visited + n + 1, false);

    int u; visited[u = 1] = true;
    while (true) {
        int mi = INF, curr = -1;

        for (int v = 1; v < n; v++) {
            if (f[u][v] < mi && not visited[v]) {
                curr = v;

                mi = f[u][v];
            }
        }

        if (curr != -1) {
            result += f[u][curr];
            visited[curr] = true;
            u = curr;
        } else break;
    }
    result += f[u][n];

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
