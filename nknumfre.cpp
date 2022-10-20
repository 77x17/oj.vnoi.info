#include <bits/stdc++.h>
using namespace std;

int a, b;

void Input() {
    cin >> a >> b;
}

int intRev(int x) {
    int result = 0;

    while (x) {
        result = result * 10 + x % 10;

        x /= 10;
    }

    return result;
}

bool Ok(int x) {
    return __gcd(x, intRev(x)) == 1;
}

void Process() {
    int result = 0;

    for (int x = a; x <= b; x++) {
        if (Ok(x)) result++;
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
