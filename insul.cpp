#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    sort(arr + 1, arr + n + 1);

    int result = 0;
    for (int i = 1; i <= n; i++) result += arr[i];
    for (int i = 1; i <= n / 2; i++) result += max(0, arr[n - i + 1] - arr[i]);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
