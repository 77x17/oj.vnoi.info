#include <bits/stdc++.h>
using namespace std;

int y;

void Input() {
    cin >> y;
}

int f[9 + 1];

void Process() {
    f[0] = 1; for (int x = 1; x <= 9; x++) f[x] = f[x - 1] * x;

    if (y == 1) {cout << 0 << '\n'; return;}

    string result;

    while (y) {
        for (int x = 9; x >= 0; x--) if (y >= f[x]) {
            y -= f[x];

            result.push_back(x + '0');

            break;
        }
    }

    reverse(result.begin(), result.end());

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
