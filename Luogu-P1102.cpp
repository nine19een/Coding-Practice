// Problem:  Luogu P1102 A-B 数对
// Link:     https://www.luogu.com.cn/problem/P1102
// Author:   nine19een
// Date:     2025-11-22

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, c, cnt;
unordered_map<ll, ll> umap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        umap[v[i]]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int p : v) {
        cnt += umap[p] * umap[p + c];
    }
    cout << cnt;
    return 0;
}
