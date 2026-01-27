// Problem:  Luogu P4503 [CTSC2014] 企鹅 QQ
// Link:     https://www.luogu.com.cn/problem/P4503
// Author:   nine19een
// Date:     2026-01-27

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e4 + 5, maxl = 205, mod1 = 1e9 + 7, P1 = 131, mod2 = 1e9 + 9, P2 = 13331;

int N, L, S, h1[maxn][maxl], p1[maxl], h2[maxn][maxl], p2[maxl];
ll ans;

void Init_p() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= L; i++) {
        p1[i] = (1ll * p1[i - 1] * P1) % mod1;
        p2[i] = (1ll * p2[i - 1] * P2) % mod2;
    }
}

void Init_s(int x, string &s) {
    for (int i = 1; i <= L; i++) {
        h1[x][i] = (1ll * h1[x][i - 1] * P1 + s[i - 1]) % mod1;
        h2[x][i] = (1ll * h2[x][i - 1] * P2 + s[i - 1]) % mod2;
    }
}

inline pair<int, int> getHash(int x, int l, int r) {
    int hash1 = (h1[x][r] - 1ll * h1[x][l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    int hash2 = (h2[x][r] - 1ll * h2[x][l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
    return {hash1, hash2};
}

void CNT(int idx) {
    vector<pair<int, int> > v;
    v.reserve(N);
    for (int i = 1; i <= N; ++i) {
        auto pre = getHash(i, 1, idx - 1);
        auto suf = getHash(i, idx + 1, L);
        int hash1 = (suf.first + 1ll * pre.first * p1[L - idx] % mod1) % mod1;
        int hash2 = (suf.second + 1ll * pre.second * p2[L - idx] % mod2) % mod2;
        v.push_back({hash1, hash2});
    }
    sort(v.begin(), v.end());
    auto last_p = v.front();
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (v[i] == last_p) {
            cnt++;
        } else {
            if (cnt > 1) {
                ans += 1ll * cnt * (cnt - 1) / 2;
            }
            cnt = 1;
        }
        last_p = v[i];
    }
    if (cnt > 1) {
        ans += cnt * (cnt - 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> S;
    Init_p();
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        Init_s(i, s);
    }
    for (int i = 1; i <= L; i++) {
        CNT(i);
    }
    cout << ans;
    return 0;
}
