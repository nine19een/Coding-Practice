// Luogu B3637 最长上升子序列
// https://www.luogu.com.cn/problem/B3637

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5005;

int n, a[maxn];
vector<int> dp;

void DP() {
    for (int i = 1; i <= n; ++i) {
        if (dp.empty() || dp.back() < a[i]) {
            dp.push_back(a[i]);
        } else {
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    DP();
    cout << (int) dp.size();
    return 0;
}
