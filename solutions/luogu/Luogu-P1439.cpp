// Luogu P1439 两个排列的最长公共子序列
// https://www.luogu.com.cn/problem/P1439

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, pos[maxn];
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        pos[a] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        int c = pos[b];
        if (dp.empty() || c > dp.back()) {
            dp.push_back(c);
        } else {
            *lower_bound(dp.begin(), dp.end(), c) = c;
        }
    }
    cout << dp.size();
    return 0;
}