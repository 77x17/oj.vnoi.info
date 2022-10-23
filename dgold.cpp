#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 24 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    int result = 0;

    for (int state = 1; state < (1 << n); state++) {
        for (int subS = state; subS >= 1; subS = (subS - 1) & state) {
            int aSum = 0, bSum = 0;

            for (int i = 1; i <= n; i++) {
                if (state & (1 << (i - 1))) {
                    if (subS & (1 << (i - 1))) aSum += arr[i];
                    else bSum += arr[i];
                }
            }

            if (aSum == bSum) result = max(result, aSum);
        }
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
