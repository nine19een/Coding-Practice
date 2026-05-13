// Problem:  Luogu P2782 友好城市
// Link:     https://www.luogu.com.cn/problem/P2782
// Author:   nine19een
// Date:     2026-01-06

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

struct City {
    int idx, val;
};

int n;
vector<City> city;
vector<int> len;

void updateLen(int x) {
    if (len.empty() || len.back() < x) {
        len.push_back(x);
        return;
    }
    auto it = lower_bound(len.begin(), len.end(), x);
    if (x == len.back() || *it == x) {
        return;
    }
    *it = x;
}

int findLen() {
    sort(city.begin(), city.end(), [](const City &a, const City &b) {
        return a.idx < b.idx;
    });
    for (City &c: city) {
        updateLen(c.val);
    }
    return (int) len.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    city.reserve(maxn);
    len.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        city.push_back({a, b});
    }
    cout << findLen();
    return 0;
}
