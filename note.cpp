#include <bits/stdc++.h>
using namespace std;

bool Calc(int f, int p) {
    if (f == 1) return false;
    if (p % 4 == 1) return true;
    if (p % 4 == 3) return false;
    return Calc(f - 1, p / 2);
}

void Process(int f, int p) {
    cout << (Calc(f, p) ? "U\n" : "D\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int f, p; while (cin >> f >> p) {
        if (f == 0 && p == 0) break;

        Process(f, p);
    }

    return 0;
}
