#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e2 + 1;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
char arr[MAX_N][MAX_N];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];
}

void Dfs(int u, int v) {
    arr[u][v] = '.';

    for (int i = 0; i < 4; i++) {
        int x = u + dx[i], y = v + dy[i];

        if (arr[x][y] == '#') Dfs(x, y);
    }
}

void Process() {
    int result = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (arr[i][j] == '#') {
        result++;

        Dfs(i, j);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
