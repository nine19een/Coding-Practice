// Problem:  Luogu P8613 [蓝桥杯 2014 省 B] 小朋友排队
// Link:     https://www.luogu.com.cn/problem/P8613
// Author:   nine19een
// Date:     2025-09-30

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const maxn = 1e5 + 5;
int n;
vector<int> a, b;

int lowbit(int x) {
    return x & -x;
}

ll query(int x, ll arr[]) {
    ll ans_q = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        ans_q += arr[i];
    }
    return ans_q;
}

void update(int x, int add, int size, ll arr[]) {
    for (int i = x; i <= size; i += lowbit(i)) {
        arr[i] += add;
    }
}

ll sum(ll x) {
    return (1 + x) * x / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a.reserve(maxn);
    b.reserve(maxn);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
        b.push_back(num);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int size = b.size();
    ll cnt_c[size + 5] = {0}, ans_a[n + 5] = {0};
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        update(idx, 1, size, cnt_c);
        ans_a[i] += i + 1 - query(idx, cnt_c);
    }
    memset(cnt_c, 0, sizeof(cnt_c));
    for (int i = n - 1; i >= 0; i--) {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        ans_a[i] += query(idx - 1, cnt_c);
        update(idx, 1, size, cnt_c);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sum(ans_a[i]);
    }
    cout << ans << endl;
    return 0;
}
