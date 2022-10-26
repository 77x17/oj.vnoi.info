#include <bits/stdc++.h>
using namespace std;

int n, k;

void Input() {
    cin >> n >> k;
}

int Calc(int x) {
    if (x <= k || (x - k) & 1) return 1;

    int a = (x - k) / 2, b = a + k;

    return Calc(a) + Calc(b);
}

void Process() {
    cout << Calc(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
