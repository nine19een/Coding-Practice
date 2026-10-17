// AtCoder Beginner Contest 480 C - Self-Stopping Shower
// https://atcoder.jp/contests/abc480/tasks/abc480_c

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, k, T, cnt;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(maxn);
    cin >> n >> k >> T;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (num >= T) {
            continue;
        }
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    n = (int) a.size();
    if (!n) {
        cout << (T + k - 1) / k;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] >= T) {
            break;
        }
        if (i == n - 1) {
            cnt += T - a[i] <= k ? 0 : (T - a[i] - 1) / k;
        }
        if (i == 0) {
            cnt += (a[i] + k - 1) / k;
            continue;
        }
        cnt += a[i] - a[i - 1] <= k ? 0 : (a[i] - a[i - 1] - 1) / k;
    }
    cout << cnt;
    return 0;
}
