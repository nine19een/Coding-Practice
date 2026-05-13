// Problem:  Luogu P3763 [TJOI2017] DNA
// Link:     https://www.luogu.com.cn/problem/P3763
// Author:   nine19een
// Date:     2026-01-26

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7, P = 131;

int t, p[maxn], h1[maxn], h2[maxn];

inline void initP() {
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = (1ll * p[i - 1] * P) % mod;
    }
}

void initH(string &s1, string &s2, int len1, int len2) {
    for (int i = 1; i <= len1; ++i) {
        h1[i] = (1ll * h1[i - 1] * P + s1[i - 1]) % mod;
    }
    for (int i = 1; i <= len2; ++i) {
        h2[i] = (1ll * h2[i - 1] * P + s2[i - 1]) % mod;
    }
}

inline int get_hash(int h[], string &s, int l, int r) {
    return (h[r] - 1ll * h[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

int Binary(string &s1, string &s2, int idx1, int idx2, int len1, int len2) {
    int l = 0, r = len2 - idx2 + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (get_hash(h1, s1, idx1 + 1, idx1 + mid) != get_hash(h2, s2, idx2 + 1, idx2 + mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l - 1;
}

bool cmp(int idx, string &s1, string &s2, int len1, int len2) {
    int cnt_diff = 0;
    int idx1 = idx, idx2 = 0;
    while (idx2 < len2) {
        int len = Binary(s1, s2, idx1, idx2, len1, len2);
        idx1 += len;
        idx2 += len;
        if (idx2 < len2) {
            cnt_diff++;
            if (cnt_diff > 3) {
                return false;
            }
        } else {
            break;
        }
        idx1++;
        idx2++;
    }
    return true;
}

void op() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    initH(s1, s2, len1, len2);
    int cnt = 0;
    for (int i = 0; i <= len1 - len2; ++i) {
        if (cmp(i, s1, s2, len1, len2)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    initP();
    while (t--) {
        op();
    }
}
