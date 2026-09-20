// Problem:  AtCoder Beginner Contest 464 C - Plumage Palette
// Link:     https://atcoder.jp/contests/abc464/tasks/abc464_c
// Author:   nine19een
// Date:     2026-06-27

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

struct Bird {
    int a, b;
};

int m, n, cur_cnt;
unordered_map<int, vector<Bird> > birds;
unordered_map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, d, b;
        cin >> a >> d >> b;
        if (d == 1 || a == b) {
            if (!cnt.count(b)) {
                cur_cnt++;
            }
            cnt[b]++;
        } else {
            if (!cnt.count(a)) {
                cur_cnt++;
            }
            cnt[a]++;
            birds[d].push_back({a, b});
        }
    }
    for (int i = 1; i <= m; i++) {
        if (birds.count(i)) {
            for (Bird bird: birds[i]) {
                int a = bird.a, b = bird.b;
                cnt[a]--;
                if (!cnt[a]) {
                    cur_cnt--;
                }
                if (!cnt.count(b) || !cnt[b]) {
                    cur_cnt++;
                }
                cnt[b]++;
            }
        }
        cout << cur_cnt << '\n';
    }
    return 0;
}
