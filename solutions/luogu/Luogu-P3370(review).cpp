// Problem:  Luogu P3370 【模板】字符串哈希
// Link:     https://www.luogu.com.cn/problem/P3370
// Author:   nine19een
// Date:     2026-01-25

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, MOD = 1e9 + 9, P = 13331;

int n, cnt;
vector<int> hash_s;

inline int Hash(string &s) {
    int val = 0;
    for (char c: s) {
        val = (1ll * val * P + c) % MOD;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    hash_s.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        hash_s.push_back(Hash(str));
    }
    sort(hash_s.begin(), hash_s.end());
    hash_s.erase(unique(hash_s.begin(), hash_s.end()), hash_s.end());
    cout << hash_s.size();
    return 0;
}