#include <bits/stdc++.h>
using namespace std;

#define s first
#define x second

const int MAX_N = (int)1e5 + 1;

int n;
pair<int, int> arr[MAX_N];

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].s >> arr[i].x;
}

int f[MAX_N];

string Process() {
    memset(f, 0, sizeof f);

    for (int i = 1; i <= n; i++) {
        if (arr[i].s == 1) {
            f[arr[i].x]++;
        } else {
            if (f[arr[i].x]) f[arr[i].x]--;
            else if (f[0]) f[0]--;
            else return "NO";
        }
    }

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        cout << Process() << '\n';
    }

    return 0;
}
