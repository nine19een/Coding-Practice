// Luogu P1181 - 数列分段 Section I
// https://www.luogu.com.cn/problem/P1181

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int cur = 0;
    while (n--) {
        int num;
        cin >> num;
        if (cur + num <= m) {
            cur += num;
        } else {
            cnt++;
            cur = num;
        }
    }
    cnt++;
    cout << cnt;
    return 0;
}