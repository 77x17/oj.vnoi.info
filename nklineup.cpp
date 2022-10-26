#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 7;
const int MAX_N = (int)5e4 + 1;

struct SegmentTree {
    int n, max_val[4 * MAX_N], min_val[4 * MAX_N];

    void init(int _n) {
        n = _n;
        fill(max_val, max_val + 4 * _n + 1, -INF);
        fill(min_val, min_val + 4 * _n + 1, INF);
    }

    void update_max(int id, int l, int r, int u, int v, int _val) {
        if (r < u || v < l) return;

        if (u <= l && r <= v) {max_val[id] = max(max_val[id], _val); return;}

        int mid = (l + r) >> 1;

        update_max(2 * id, l, mid, u, v, _val);
        update_max(2 * id + 1, mid + 1, r, u, v, _val);

        max_val[id] = max(max_val[2 * id], max_val[2 * id + 1]);
    }

    int get_max(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return -INF;

        if (u <= l && r <= v) return max_val[id];

        int mid = (l + r) >> 1;

        return max(get_max(2 * id, l, mid, u, v), get_max(2 * id + 1, mid + 1, r, u, v));
    }

    void update_min(int id, int l, int r, int u, int v, int _val) {
        if (r < u || v < l) return;

        if (u <= l && r <= v) {min_val[id] = min(min_val[id], _val); return;}

        int mid = (l + r) >> 1;

        update_min(2 * id, l, mid, u, v, _val);
        update_min(2 * id + 1, mid + 1, r, u, v, _val);

        min_val[id] = min(min_val[2 * id], min_val[2 * id + 1]);
    }

    int get_min(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return INF;

        if (u <= l && r <= v) return min_val[id];

        int mid = (l + r) >> 1;

        return min(get_min(2 * id, l, mid, u, v), get_min(2 * id + 1, mid + 1, r, u, v));
    }

    void update(int i, int _val) {
        update_max(1, 1, n, i, i, _val); update_min(1, 1, n, i, i, _val);
    }

    int get_max(int u, int v) {
        return get_max(1, 1, n, u, v);
    }

    int get_min(int u, int v) {
        return get_min(1, 1, n, u, v);
    }
} st;

int n, q, arr[MAX_N];

void Input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    st.init(n);
    for (int i = 1; i <= n; i++) st.update(i, arr[i]);

    while (q--) {
        int l, r; cin >> l >> r;

        cout << st.get_max(l, r) - st.get_min(l, r) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
