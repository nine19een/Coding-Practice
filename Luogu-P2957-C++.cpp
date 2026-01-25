// Problem:  Luogu P2957 [USACO09OCT] Barn Echoes G
// Link:     https://www.luogu.com.cn/problem/P2957
// Author:   nine19een
// Date:     2026-01-25

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 100, MOD = 1e9 + 9, P = 13331;

string s1, s2;
int h1[maxn], h2[maxn], p[maxn];

void Init(int len1, int len2) {
    p[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p[i] = (1ll * p[i - 1] * P) % MOD;
    }
    for (int i = 1; i <= len1; i++) {
        h1[i] = (1ll * h1[i - 1] * P + s1[i - 1]) % MOD;
    }
    for (int i = 1; i <= len2; i++) {
        h2[i] = (1ll * h2[i - 1] * P + s2[i - 1]) % MOD;
    }
}

inline int get_hash(int h[], int l, int r) {
    return (h[r] - (1ll * h[l - 1] * p[r - l + 1] % MOD) + MOD) % MOD;
}

int max_same_length(int len1, int len2) {
    int len = min(len1, len2);
    int max_len = 0;
    for (int i = 1; i <= len; i++) {
        if (get_hash(h1, 1, i) == get_hash(h2, len2 - i + 1, len2)) {
            max_len = max(max_len, i);
        }
        if (get_hash(h1, len1 - i + 1, len1) == get_hash(h2, 1, i)) {
            max_len = max(max_len, i);
        }
    }
    return max_len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    Init(len1, len2);
    cout << max_same_length(len1, len2);
    return 0;
}
