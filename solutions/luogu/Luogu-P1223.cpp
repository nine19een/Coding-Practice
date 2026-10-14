// Luogu P1223 排队接水
// https://www.luogu.com.cn/problem/P1223

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1005;

struct People {
    int t, id;
};

int n;
double sum;
vector<People> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    v.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int ti;
        cin >> ti;
        v.push_back({ti, i});
    }
    sort(v.begin(), v.end(), [](const People &a, const People &b) {
        if (a.t != b.t) {
            return a.t < b.t;
        }
        return a.id < b.id;
    });
    for (int i = 0; i < n; ++i) {
        sum += v[i].t * (n - i - 1) * 1.0;
    }
    sum /= n;
    for (auto p: v) {
        cout << p.id << " ";
    }
    cout << '\n';
    cout << fixed << setprecision(2) << sum;
    return 0;
}
