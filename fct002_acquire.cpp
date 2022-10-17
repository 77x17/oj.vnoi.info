#include <bits/stdc++.h>
using namespace std;

#define w first
#define h second

const int MAX_N = (int)5e4 + 1;
const int LOG = log(MAX_N) / log(2) + 1;

int sparse[MAX_N][LOG];

int getMax(int l, int r) {
    int k = log(r - l + 1) / log(2);

    return max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

void buildSparseTable(int n, pair<int, int> arr[]) {
    for (int k = 0; k < LOG; k++) {
        for (int i = 1; i <= n; i++) sparse[i][k] = 0;
    }

    for (int i = 1; i <= n; i++) sparse[i][0] = arr[i].h;

    for (int k = 0; k < LOG; k++) {
        for (int i = 1; i + (1 << k) <= n; i++) {
            sparse[i][k + 1] = max(sparse[i][k], sparse[i + (1 << k)][k]);
        }
    }
}

int n;
pair<int, int> arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].w >> arr[i].h;
}

int k = 1;

void Prepare() {
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        while (k >= 2 && arr[k - 1].h <= arr[i].h) k--;

        arr[k++] = arr[i];
    }

    n = k - 1;

    buildSparseTable(n, arr);

    for (int i = 1; i <= n; i++) cout << arr[i].w << ' ' << arr[i].h << '\n';
}

long long dp[MAX_N];

void Process() {
    for (int i = 1; i <= n; i++) dp[i] = LLONG_MAX; dp[0] = 0;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, arr[i].h), dp[i] = mx * arr[i].w;
    }

    int temp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j + 1 <= n; j++) {
            if (dp[n] > dp[i - 1] + getMax(i, j) * arr[j].w + getMax(j + 1, n) * arr[n].w) {
                dp[n] = dp[i - 1] + getMax(i, j) * arr[j].w + getMax(j + 1, n) * arr[n].w;

                dp[j] = dp[i - 1] + getMax(i, j) * arr[j].w;

                i = j;

                break;
            }
        }
    }

    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
