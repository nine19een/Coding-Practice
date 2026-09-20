// Luogu P2870 - [USACO07DEC] Best Cow Line G
// https://www.luogu.com.cn/problem/P2870

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr int maxn = 5e5 + 5, P = 131;

int n;
char s[maxn];
string ans;
ull p[maxn], h1[maxn], h2[maxn];


ull getHash1(int l, int r) {
    return h1[r] - h1[l - 1] * p[r - l + 1];
}

ull getHash2(int l, int r) {
    return h2[l] - h2[r + 1] * p[r - l + 1];
}

bool cmp(int l, int r) {
    int low = 1, high = (r - l + 1) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (getHash1(l, l + mid - 1) == getHash2(r - mid + 1, r)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int same_len = low - 1;
    return s[l + same_len] < s[r - same_len];
}

void init() {
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * P;
        h1[i] = h1[i - 1] * P + s[i];
    }
    for (int i = n; i >= 1; --i) {
        h2[i] = h2[i + 1] * P + s[i];
    }
}

void Print() {
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if ((i + 1) % 80 == 0) {
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    init();
    int l = 1, r = n;
    while (l <= r) {
        bool choose_left;
        if (s[l] < s[r]) {
            choose_left = true;
        } else if (s[l] > s[r]) {
            choose_left = false;
        } else {
            choose_left = cmp(l, r);
        }
        if (choose_left) {
            ans += s[l++];
        } else {
            ans += s[r--];
        }
    }
    Print();
    return 0;
}
