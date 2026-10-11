// Luogu P2036 [COCI 2008/2009 #2] PERKET
// https://www.luogu.com.cn/problem/P2036

#include <bits/stdc++.h>
using namespace std;

int n, s[15], b[15], ans = 1e9 + 5;

void DFS(int x, int S, int B, int cnt) {
    if (x > n) {
        if (cnt) {
            ans = min(ans, abs(S - B));
        }
        return;
    }
    DFS(x + 1, S, B, cnt);
    DFS(x + 1, S * s[x], B + b[x], cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> b[i];
    }
    DFS(1, 1, 0, 0);
    cout << ans;
    return 0;
}
