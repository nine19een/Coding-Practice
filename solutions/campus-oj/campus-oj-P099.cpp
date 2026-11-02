// Campus OJ P099 修改一个数后的最长等差段
// https://oj.nine19een.com/#library/P099

#include <bits/stdc++.h>
using namespace std;

int t;

void init(vector<int> &a, vector<int> &l, vector<int> &r, int n, int &ans) {
    l[1] = 1, l[2] = 2, r[n] = 1, r[n - 1] = 2;
    for (int i = 3; i <= n; ++i) {
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 2;
        }
        ans = max(ans, l[i]);
    }
    for (int i = n - 2; i > 0; --i) {
        if (a[i + 1] - a[i] == a[i + 2] - a[i + 1]) {
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 2;
        }
        ans = max(ans, r[i]);
    }
}

void dp(vector<int> &a, vector<int> &l, vector<int> &r, int n, int &ans) {
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            ans = max(ans, l[i - 1] + 1);
        }
        if (i < n) {
            ans = max(ans, r[i + 1] + 1);
        }
        if (1 < i && i < n) {
            int delta = a[i + 1] - a[i - 1];
            if (delta & 1) {
                continue;
            }
            int left, right;
            int d = delta / 2;
            if (i >= 3 && a[i - 1] - a[i - 2] == d) {
                left = l[i - 1];
            } else {
                left = 1;
            }
            if (i <= n - 2 && a[i + 2] - a[i + 1] == d) {
                right = r[i + 1];
            } else {
                right = 1;
            }
            ans = max(ans, left + 1 + right);
        }
    }
}

void solve() {
    int n, ans = 2;
    cin >> n;
    vector<int> a(n + 5), l(n + 5), r(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    init(a, l, r, n, ans);
    dp(a, l, r, n, ans);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}
