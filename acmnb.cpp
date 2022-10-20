#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAX_N = (int)8e5 + 1;

int n;
pair<int, int> arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= 2 * n; i++) cin >> arr[i].fi >> arr[i].se;
}

bool Comp(pair<int, int> x, pair<int, int> y) {
    return x.fi - x.se < y.fi - y.se;
}

void Process() {
    sort(arr + 1, arr + 2 * n + 1, Comp);

    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += arr[i].fi;
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        result += arr[i].se;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
