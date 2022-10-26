#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

bool dead[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Process() {
    fill(dead, dead + n + 1, false);
    for (int i = 1; i <= n; i++) pq.emplace(arr[i], i);

    int result = 0;
    while (pq.size()) {
        int x = pq.top().second; pq.pop();

        result++;

        for (int i = -1; i <= 1; i++) dead[x + i] = true;

        while (pq.size() && dead[pq.top().second]) pq.pop();
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
