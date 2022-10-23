#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 7;
const int MAX_N = (int)1e6 + 1;

struct MonotoneQueue {
    // value / index
    deque<pair<int, int>> dq;

    void push(int val, int idx) {
        while (dq.size() && dq.back().first > val) dq.pop_back();

        dq.emplace_back(val, idx);
    }

    int min() {
        return dq.front().first;
    }

    int lastMinIdx() {
        return dq.front().second;
    }

    void pop(int idx) {
        if (dq.front().second == idx) dq.pop_front();
    }
};

int n, k, arr[MAX_N];

void Input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int f[MAX_N];

void Process() {
    MonotoneQueue mq;

    for (int i = 1; i <= n; i++) {
        mq.push(arr[i], i);

        if (i - k + 1 >= 1) {
            f[i - k + 1] = mq.min();
            mq.pop(i - k + 1);
        }
    }

    cout << "f: "; for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
