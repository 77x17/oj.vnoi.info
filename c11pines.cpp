#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e4 + 1;

int n, d, arr[MAX_N];

void Input() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

bool cantFindSolution() {
    int anchor = arr[1] % d;
    for (int i = 2; i <= n; i++) if (arr[i] % d != anchor) return true;
    return false;
}

void Process() {
    if (cantFindSolution()) {cout << -1 << '\n'; return;}

    sort(arr + 1, arr + n + 1);

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += (arr[i] - arr[1]) / d;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
