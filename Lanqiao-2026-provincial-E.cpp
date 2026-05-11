// Problem:  蓝桥杯 2026 省 B - E.LQ 聚合
// Link:     https://www.luogu.com.cn/problem/P16236
// Author:   nine19een
// Date:     2026-05-11

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, preL[maxn], preQ[maxn], totQ;
ll ans, cur;
vector<int> idx;
string s;

void init() {
    for (int i = 0; i < n; i++) {
        if (i >= 1) {
            preL[i] = preL[i - 1];
            preQ[i] = preQ[i - 1];
        }
        if (s[i] == 'L') {
            preL[i]++;
        } else {
            preQ[i]++;
            totQ++;
            if (s[i] == '?') {
                idx.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            cur += totQ - preQ[i];
        }
    }
    ans = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    s.reserve(maxn);
    idx.reserve(maxn);
    cin >> n >> s;
    init();
    int size = (int) idx.size();
    for (int i = 0; i < size; ++i) {
        ll lose = i + (idx[i] ? preL[idx[i] - 1] : 0);
        ll gain = totQ - preQ[idx[i]];
        ans = max(ans, cur = cur - lose + gain);
    }
    cout << ans;
    return 0;
}
