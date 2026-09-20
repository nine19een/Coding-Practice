// Luogu P1181 - 数列分段 Section I
// https://www.luogu.com.cn/problem/P1181

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5;

int n, m, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (cur + num > m) {
            cnt++;
            cur = num;
        } else {
            cur += num;
        }
    }
    cnt++;
    cout << cnt;
    return 0;
}