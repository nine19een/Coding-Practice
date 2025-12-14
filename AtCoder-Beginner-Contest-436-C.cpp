// Problem:  AtCoder Beginner Contest 436 C - 2x2 Placing
// Link:     https://atcoder.jp/contests/abc436/tasks/abc436_c
// Author:   nine19een
// Date:     2025-12-13

#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 1, 0}, dy[] = {0, 0, 1, 1};

int n, m, cnt;
unordered_map<int, unordered_set<int> > ump;

bool available(int x, int y) {
    return x <= n && y <= n && (!ump.count(x) || !ump[x].count(y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        bool fill = true;
        for (int j = 0; j < 4; ++j) {
            if (!available(x + dx[j], y + dy[j])) {
                fill = false;
                break;
            }
        }
        if (fill) {
            cnt++;
            for (int j = 0; j < 4; ++j) {
                ump[x + dx[j]].insert(y + dy[j]);
            }
        }
    }
    cout << cnt;
}
