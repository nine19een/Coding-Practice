// Campus OJ P169 训练室答疑点
// https://oj.nine19een.com/#library/P169

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 5, INF = 1e9 + 5;

int n, k, c, pos[maxn];

bool ck(int x) {
    int cnt = 0, l = 1;
    int mid, r;
    while (l <= n) {
        cnt++;
        if (cnt > k) {
            return false;
        }
        mid = upper_bound(pos + l, pos + n + 1, pos[l] + x) - pos - 1;
        r = upper_bound(pos + l, pos + n + 1, pos[mid] + x) - pos - 1;
        if (c <= r - l + 1) {
            l += c;
        } else {
            l = r + 1;
        }
    }
    return true;
}

int Binary() {
    int l = 0, r = pos[n] - pos[1] + 5;
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (ck(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + n + 1);
    cout << Binary();
    return 0;
}
