#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;

#define fi first
#define se second

int n; long long b;
pair<long long, long long> arr[MAX_N];

void Input() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> arr[i].fi >> arr[i].se;
}

void Process() {
    sort(arr + 1, arr + n + 1);

    long long result = 0;

    for (int i = 1; i <= n; i++) {
        long long k = min(b / arr[i].fi, arr[i].se);

        result += k;

        b -= arr[i].fi * k;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
