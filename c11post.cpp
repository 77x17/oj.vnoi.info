// https://oj.vnoi.info/problem/c11post

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m; vector<vector<char>> arr; vector<vector<int>> h;

void Input() {
    cin >> n >> m; arr.assign(n + 1, vector<char> (m + 1, 0)); h.assign(n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> h[i][j];
}

vector<int> order;
int k, mi, mx; array<int, 2> s = {-1, -1};

void Prepare() {
    k = 0, mi = inf, mx = 0; order.clear();

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (arr[i][j] == 'K') k++;

        if (arr[i][j] == 'P') s[0] = i, s[1] = j;

        order.push_back(h[i][j]);

        if (arr[i][j] != '.') mi = min(mi, h[i][j]), mx = max(mx, h[i][j]);
    }

    sort(order.begin(), order.end()); order.resize(unique(order.begin(), order.end()) - order.begin());
}

vector<vector<bool>> visited;

bool Bfs(int l, int r) {
    int cnt = 0; queue<array<int, 2>> q;

    visited.assign(n + 1, vector<bool> (m + 1, false));

    q.push({s[0], s[1]}); visited[s[0]][s[1]] = true;

    while (q.size()) {
        int u = q.front()[0], v = q.front()[1]; q.pop();

        for (int i = 0; i < 8; i++) {
            u += dx[i], v += dy[i];

            if (1 <= u && u <= n && 1 <= v && v <= m && not visited[u][v] && l <= h[u][v] && h[u][v] <= r) {
                cnt += (arr[u][v] == 'K');

                if (cnt == k) return true;

                q.push({u, v}); visited[u][v] = true;
            }

            u -= dx[i], v -= dy[i];
        }
    }

    return cnt == k;
}

bool Ok(int anchor) {
    for (int x : order) if (x <= h[s[0]][s[1]] && h[s[0]][s[1]] <= x + anchor) {
        if (x <= mi && mx <= x + anchor) if (Bfs(x, x + anchor)) return true;
    }

    return false;
}

void Process() {
    int l = 0, r = inf, result = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (Ok(mid)) result = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Prepare();

    Process();

    return 0;
}
