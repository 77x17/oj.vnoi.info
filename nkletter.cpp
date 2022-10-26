#include <bits/stdc++.h>
using namespace std;

string a, b;

void Input() {
    cin >> a >> b;
}

string getStr(string s, int l, int r) {
    return s.substr(l, r - l + 1);
}

void Process() {
    for (int i = 0; i < a.size(); i++) {
        if (b.find(getStr(a, i, a.size() - 1)) == 0) {
            cout << (int)b.size() + i << '\n'; return;
        }
    }

    cout << (int)a.size() + (int)b.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
