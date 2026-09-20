// Problem:  Luogu P12834 [蓝桥杯 2025 国 B] 项链排列
// Link:     https://www.luogu.com.cn/problem/P12834
// Author:   nine19een
// Date:     2026-06-04

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e6 + 10;

int a, b, c;
string ans;

bool available(char last_char, int rest_L, int rest_Q, int rest_c) {
    int dif = rest_Q, same = rest_L;
    if (last_char == 'Q') {
        swap(dif, same);
    }
    int min_changes = !dif ? 0 : 1;
    int max_changes = dif <= same ? dif * 2 : same * 2 + 1;
    return min_changes <= rest_c && rest_c <= max_changes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ans.reserve(maxn);
    cin >> a >> b >> c;
    int len = a + b;
    for (int i = 0; i < len; ++i) {
        bool noAns = true;
        int rest_c;
        if (a) {
            rest_c = c;
            if (!ans.empty() && ans.back() == 'Q') {
                rest_c--;
            }
            if (available('L', a - 1, b, rest_c)) {
                c = rest_c;
                ans += 'L';
                a--;
                noAns = false;
            }
        }
        if (noAns && b) {
            rest_c = c;
            if (!ans.empty() && ans.back() == 'L') {
                rest_c--;
            }
            if (available('Q', a, b - 1, rest_c)) {
                c = rest_c;
                ans += 'Q';
                b--;
                noAns = false;
            }
        }
        if (noAns) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
