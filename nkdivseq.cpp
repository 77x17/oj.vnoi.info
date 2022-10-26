#include <bits/stdc++.h>
using namespace std;

int n;

void Input() {
    cin >> n;
}

vector<int> order;

void Process() {
    int x = 1, k = 1;
    while (order.size() != n) {
        while (x % k != 0) x++;

        for (int i = 1; order.size() != n && i <= k; i++) order.push_back(x), x += k;

        x -= k;

        x++, k++;
    }
    cout << order.back() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
