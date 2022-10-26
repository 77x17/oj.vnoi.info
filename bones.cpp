#include <bits/stdc++.h>
using namespace std;

const int MAX_C = 80 + 1;

int s1, s2, s3;

void Input() {
    cin >> s1 >> s2 >> s3;
}

int cnt[MAX_C];

void Process() {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                cnt[i + j + k]++;
            }
        }
    }

    int result = 0;
    for (int i = 1; i < MAX_C; i++) result = max(result, cnt[i]);
    for (int i = 1; i < MAX_C; i++) if (result == cnt[i]) {cout << i << '\n'; return;}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
