// Luogu P1102 - A-B 数对
// https://www.luogu.com.cn/problem/P1102

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, c, a[maxn];
unordered_map<int, int> cnt;
ll sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        int A = a[i] + c;
        if (cnt.count(A)) {
            sum += cnt[A];
        }
    }
    cout << sum;
    return 0;
}