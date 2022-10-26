#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int prefix[MAX_N], suffix[MAX_N], sum[MAX_N];

void Process() {
    prefix[0] = prefix[1] = arr[1];
    for (int i = 2; i <= n; i++) prefix[i] = min(prefix[i - 1], prefix[0] += arr[i]);

    suffix[n] = arr[n];
    for (int i = n - 1; i >= 1; i--) suffix[i] = min(suffix[i + 1] + arr[i], arr[i]);

    sum[n] = arr[n];
    for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + arr[i];

    int result =  0;
    for (int i = 1; i <= n; i++) if (suffix[i] > 0 && prefix[i] + sum[i] > 0) result++;
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
