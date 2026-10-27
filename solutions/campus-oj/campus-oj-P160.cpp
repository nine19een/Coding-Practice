// Campus OJ P160 灯光的两种节奏
// https://oj.nine19een.com/#library/P160

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n;
vector<int> a;

int LIS() {
    vector<int> dp;
    dp.reserve(n + 5);
    for (int x: a) {
        if (dp.empty() || dp.back() < x) {
            dp.push_back(x);
        } else {
            *lower_bound(dp.begin(), dp.end(), x) = x;
        }
    }
    return dp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    cout << LIS() << " ";
    reverse(a.begin(), a.end());
    cout << LIS();
    return 0;
}