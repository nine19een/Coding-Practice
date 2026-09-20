// Problem:  Luogu P4391 [BalticOI 2009] Radio Transmission 无线传输
// Link:     https://www.luogu.com.cn/problem/P4391
// Author:   nine19een
// Date:     2026-01-25

#include <bits/stdc++.h>
using namespace std;
int const maxl = 1e6 + 5, mod = 1e9 + 7, P = 131;

int L, p[maxl], h[maxl];
string s;

void Init() {
    p[0] = 1;
    for (int i = 1; i <= L; i++) {
        p[i] = (1ll * p[i - 1] * P) % mod;
        h[i] = (1ll * h[i - 1] * P + s[i - 1]) % mod;
    }
}

inline int get_hash(int l, int r) {
    return (h[r] - 1ll * h[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

inline bool isSubstring(int x) {
    int len = L - x;
    return get_hash(1, len) == get_hash(L - len + 1, L);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> s;
    Init();
    for (int i = 1; i <= L; i++) {
        if (isSubstring(i)) {
            cout << i;
            return 0;
        }
    }
}
