#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e3 + 1;

int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> arr[i];
}

void Process() {
    sort(arr + 1, arr + m + 1);

    int cost = 0, result = 0;

    for (int i = max(1, m - n + 1); i <= m; i++) {
        if (result < arr[i] * (m - i + 1)) {
            result = arr[i] * (m - i + 1);

            cost = arr[i];
        }
    }
    cout << cost << ' ' << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
