#include <bits/stdc++.h>
using namespace std;

const int MOD = 20122007;

int pow_mod(int x, int k) {
    if (k == 0) return 1;

    int result = pow_mod(x, k >> 1);

    result = 1LL * result * result % MOD;

    if (k & 1) result = 1LL * result * x % MOD;

    return result;
}

int a;

void Input() {
    cin >> a;
}

void Process() {
    int result = 1;
    for (int x = 1; x * x <= a; x++) if (a % x == 0) {
        result = 1LL * result * (pow_mod(3, x) - 1) % MOD;

        if (x * x != a) result = 1LL * result * (pow_mod(3, a / x) - 1) % MOD;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
