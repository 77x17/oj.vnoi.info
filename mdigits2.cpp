#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void Input() {
    cin >> n;
}

void Process() {
    for (int i = 1; i <= n; i++) {
        s += (to_string(i));
    }

    cout << s.find(to_string(n)) + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
