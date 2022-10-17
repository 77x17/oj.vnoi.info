#include <bits/stdc++.h>
using namespace std;

#define bigInt vector<int>

const int BASE = 1e9;
const int LENGTH = 9;

bigInt toBigInt(int x) {
    bigInt result;

    result.push_back(x);

    return result;
}

bigInt operator + (bigInt x, bigInt y) {
    bigInt result;

    int carry = 0;
    for (int i = 0; i < max((int)x.size(), (int)y.size()); i++) {
        if (i < (int)x.size()) carry += x[i];
        if (i < (int)y.size()) carry += y[i];

        result.push_back(carry % BASE);

        carry /= BASE;
    }

    if (carry) result.push_back(carry);

    return result;
}

bigInt operator * (bigInt x, int k) {
    bigInt result;

    long long carry = 0;
    for (int i = 0; i < (int)x.size(); i++) {
        carry += x[i] * k;

        result.push_back(carry % BASE);

        carry /= BASE;
    }

    if (carry) result.push_back(carry);

    return result;
}

bigInt operator + (bigInt x, int y) {
    return x + toBigInt(y);
}

void operator << (ostream &out, bigInt x) {
    while ((int)x.size() >= 2 && x.back() == 0) x.pop_back();

    cout << x.back(); x.pop_back();

    reverse(x.begin(), x.end());

    for (int val : x) cout << setw(LENGTH) << setfill('0') << val;

    cout << '\n';
}

bigInt Calc(int p, int q) {
    if (p == q) return toBigInt(0);

    if (p - q >= 0) return Calc(p - q, q) * 2 + 2;

    return Calc(p, q - p) * 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int p, q;
    while (cin >> p >> q) cout << Calc(p, q);

    return 0;
}
