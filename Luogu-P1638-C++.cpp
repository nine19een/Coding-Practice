// Problem:  Luogu P1638 逛画展
// Link:     https://www.luogu.com.cn/problem/P1638
// Author:   nine19een
// Date:     2026-03-18

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 5, maxm = 2e3 + 5;

int n, m, a[maxn], cnt[maxm], min_dis = 1e9, ans_l, ans_r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 1, cnt_artist = 0;
    for (; r <= n; ++r) {
        if (++cnt[a[r]] == 1) {
            cnt_artist++;
        }
        if (cnt_artist == m) {
            break;
        }
    }
    while (r <= n && l <= r) {
        if (min_dis > r - l) {
            min_dis = r - l;
            ans_l = l, ans_r = r;
        }
        if (cnt[a[l]] > 1) {
            cnt[a[l++]]--;
        } else {
            if (r == n) {
                break;
            }
            cnt[a[++r]]++;
        }
    }
    cout << ans_l << " " << ans_r;
    return 0;
}
