// Luogu P1296 奶牛的耳语
// https://www.luogu.com.cn/problem/P1296

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 5;

int n, d;
vector<int> cow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cow.reserve(maxn);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        int pos;
        cin >> pos;
        cow.push_back(pos);
    }
    sort(cow.begin(), cow.end());
    ll cnt = 0;
    for (auto it = cow.begin(); it != cow.end(); ++it) {
        cnt += 1ll * (upper_bound(it, cow.end(), *it + d) - it) - 1;
    }
    cout << cnt;
    return 0;
}
