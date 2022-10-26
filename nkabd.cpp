#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e5 + 1;

int l, r;

void Input() {
    cin >> l >> r;
}

int f[MAX_N];

void Prepare() {
    for (int i = 1; i * 2 < MAX_N; i++) {
        for (int j = i * 2; j < MAX_N; j += i) f[j] += i;
    }
}

void Process() {
    int result = 0;
    for (int i = l; i <= r; i++) result += (f[i] > i);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();
    Prepare();
    Process();

    return 0;
}
