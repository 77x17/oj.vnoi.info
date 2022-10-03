// https://oj.vnoi.info/problem/mtriarea

#include <bits/stdc++.h>
using namespace std;

#define point pair<int, int>
#define x first
#define y second

void operator -= (point & a, point b) {a.x -= b.x, a.y -= b.y;}

// counterClockWise
bool ccw(point a, point b, point c) {
    c -= b, b -= a;

    return b.x * c.y > b.y * c.x;
}

int n; vector<point> arr;

void Input() {
    cin >> n; arr.assign(n + 1, {0, 0});

    for (int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;
}

void convexHull() {
    int anchor = 2; vector<int> order;

    for (int i = 1; i <= n; i++) {
        while (order.size() >= anchor && ccw(arr[order[order.size() - 2]], arr[order.back()], arr[i])) order.pop_back();

        order.push_back(i);
    }

    anchor += order.size();

    for (int i = n; i >= 1; i--) {
        while (order.size() >= anchor && ccw(arr[order[order.size() - 2]], arr[order.back()], arr[i])) order.pop_back();

        order.push_back(i);
    }

    vector<bool> visited(n + 1, false); for (int x : order) visited[x] = true;

    int cnt = 0;

    for (int i = 1; i <= n; i++) if (visited[i]) arr[cnt++] = arr[i];

    n = cnt - 1;
}

int Area(point a, point b, point c) {
    return abs(1ll * a.x * (b.y - c.y) + 1ll * b.x * (c.y - a.y) + 1ll * c.x * (a.y - b.y));
}

int Area(int a, int b, int c) {
    return Area(arr[a], arr[b], arr[c]);
}

void Process() {
    sort(arr.begin() + 1, arr.end());

    convexHull();

    int result = 0;

    for (int i = 0; i < n; i++) cout << arr[i].x << ' ' << arr[i].y << '\n';

    for (int i = 0, j = 1, k = 2; i < n; i++) {
        if (i == j) j = (j + 1) % n;
        if (j == k) k = (k + 1) % n;

        while (true) {
            while (Area(i, j, k) <= Area(i, j, (k + 1) % n)) k = (k + 1) % n;

            if (Area(i, j, k) <= Area(i, (j + 1) % n, k)) j = (j + 1) % n; else break;
        }

        result = max(result, Area(i, j, k));
    }

    cout << result / 2 << ((result & 1) ? ".50\n" : ".00\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("Mtriarea.inp", "r", stdin);
	freopen("Mtriarea.out", "w", stdout);

    while (true) {
        Input();

        if (n == -1) return 0;

        Process();
    }
}
