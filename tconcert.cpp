#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAX_M = (int)4e5 + 1;

struct single {
    int a, b, c;
};

// sweptData
struct swData {
    int s, x, id;

    swData(int _s = 0, int _x = 0, int _id = 0) {
        s = _s, x = _x, id = _id;
    }

    bool operator < (const swData& y) const {
        return x < y.x || (x == y.x && s < y.s) || (x == y.x && s == y.s && id < y.id);
    }
};

int n, m;
single arr[MAX_M];

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> arr[i].a >> arr[i].b >> arr[i].c;
}

set<int> qu;
vector<swData> order;

void Process() {
    for (int i = 1; i <= m; i++) {
        order.push_back(swData(0, arr[i].a, i));
        order.push_back(swData(1, arr[i].b, i));
    }

    sort(order.begin(), order.end());

    unsigned long long result = 0;

    for (swData y : order) {
        if (y.s == 0) {
            qu.insert(y.id);
        } else {
            qu.erase(y.id);

            for (auto i : qu) {
                result += 1LL * arr[y.id].c * arr[i].c
                          * (min(arr[y.id].b, arr[i].b) - max(arr[y.id].a, arr[i].a) + 1);
            }
        }
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
