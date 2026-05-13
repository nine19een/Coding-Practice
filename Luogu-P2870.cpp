// Problem:  Luogu P2870 [USACO07DEC] Best Cow Line G
// Link:     https://www.luogu.com.cn/problem/P2870
// Author:   nine19een
// Date:     2026-01-25

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, mod = 1e9 + 7, P = 131;

int n, p[maxn], h1[maxn], h2[maxn];
char s[maxn], ans[maxn];

void Init() {
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (1ll * p[i - 1] * P) % mod;
        h1[i] = (1ll * h1[i - 1] * P + s[i]) % mod;
        h2[n - i + 1] = (1ll * h2[n - i + 2] * P + s[n - i + 1]) % mod;
    }
}

inline int get_hash1(int l, int r) {
    return (h1[r] - 1ll * h1[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

inline int get_hash2(int l, int r) {
    return (h2[l] - 1ll * h2[r + 1] * p[r - l + 1] % mod + mod) % mod;
}

bool Binary(int l, int r) {
    int low = 1, high = r - l + 2;
    while (low < high) {
        int mid = (low + high) / 2;
        if (get_hash1(l, l + mid - 1) == get_hash2(r - mid + 1, r)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (s[l + low - 1] < s[r - high + 1]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    Init();
    int L = 1, R = n;
    int idx_ans = 1;
    while (L <= R) {
        bool pick_left = false;
        if (s[L] < s[R]) {
            pick_left = true;
        } else if (s[L] > s[R]) {
            pick_left = false;
        } else {
            pick_left = Binary(L, R);
        }
        if (pick_left) {
            ans[idx_ans++] = s[L++];
        } else {
            ans[idx_ans++] = s[R--];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (!(i % 80)) {
            cout << '\n';
        }
    }
    return 0;
}
