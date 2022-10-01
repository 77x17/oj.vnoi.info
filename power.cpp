#include <bits/stdc++.h>
using namespace std;

long long l, r;

void Input() {
    cin >> l >> r;
}

bool Ok(int x) {
    int u = ceil(log10(l) / log10(x)), v = floor(log10(r) / log10(x));

    return (u <= v);
}

void Process() {
    int x = 2;

    while (not Ok(x)) x++;

    cout << floor(log10(r) / log10(x)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;

    for (int i = 1; i <= t; i++) {
        Input();

        cout << "Case #" << i << ": "; Process();
    }

    return 0;
}
