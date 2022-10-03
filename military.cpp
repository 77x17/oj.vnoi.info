// https://oj.vnoi.info/problem/military

#include <bits/stdc++.h>
using namespace std;

#define point pair<int, int>
#define x first
#define y second

void operator -= (point& a, point b) {a.x -= b.x, a.y -= b.y;}

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

    for (int i = 1; i <= n; i++) if (not visited[i]) arr[++cnt] = arr[i];

    n = cnt;
}

void Process() {
    sort(arr.begin() + 1, arr.end(), comp);

    int result = 0;

    while (n >= 3) convexHull(), result++;

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
