// Problem:  AtCoder Beginner Contest 445 D - Reconstruct Chocolate
// Link:     https://atcoder.jp/contests/abc443/tasks/abc445_d
// Author:   nine19een
// Date:     2026-02-14

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

struct Rectangle {
    int idx;
    int h, w;
} rec[maxn];

int H, W, n;
unordered_map<int, vector<Rectangle> > um_h, um_w;
bool vis[maxn];
pair<int, int> ans[maxn];

void chocolate(int cur_idx, int cur_h, int cur_w, pair<int, int> cur_coord) {
    for (int i = 1; i <= n; i++) {
        vis[cur_idx] = true;
        ans[cur_idx] = cur_coord;
        if (rec[cur_idx].h == cur_h) {
            cur_w -= rec[cur_idx].w;
            cur_coord.second += rec[cur_idx].w;
        } else {
            cur_h -= rec[cur_idx].h;
            cur_coord.first += rec[cur_idx].h;
        }
        if (um_h.count(cur_h) && !um_h[cur_h].empty()) {
            auto &h = um_h[cur_h];
            while (!h.empty() && vis[h.back().idx]) {
                h.pop_back();
            }
            if (!h.empty()) {
                cur_idx = h.back().idx;
                h.pop_back();
                continue;
            }
        }
        if (um_w.count(cur_w) && !um_w[cur_w].empty()) {
            auto &w = um_w[cur_w];
            while (!w.empty() && vis[w.back().idx]) {
                w.pop_back();
            }
            if (!w.empty()) {
                cur_idx = w.back().idx;
                w.pop_back();
                continue;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W >> n;
    int start_idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> rec[i].h >> rec[i].w;
        um_h[rec[i].h].push_back({i, rec[i].h, rec[i].w});
        um_w[rec[i].w].push_back({i, rec[i].h, rec[i].w});
        if (rec[i].h == H || rec[i].w == W) {
            start_idx = i;
        }
    }
    chocolate(start_idx, H, W, {1, 1});
    for (int i = 1; i <= n; i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}
