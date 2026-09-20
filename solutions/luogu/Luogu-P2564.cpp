// Problem:  Luogu P2564 [SCOI2009] 生日礼物
// Link:     https://www.luogu.com.cn/problem/P2564
// Author:   nine19een
// Date:     2026-03-18

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 5, maxk = 65;

int n, k, cnt[maxk], min_dis = 1e9;
unordered_map<int, vector<int> > mp;
vector<int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pos.reserve(maxn);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; ++j) {
            int idx;
            cin >> idx;
            pos.push_back(idx);
            mp[idx].push_back(i);
        }
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    int cnt_kind = 0, l = 0, r = 0;
    int size = (int) pos.size();
    for (; r < size; ++r) {
        for (int p: mp[pos[r]]) {
            if (++cnt[p] == 1) {
                cnt_kind++;
            }
        }
        if (cnt_kind == k) {
            break;
        }
    }
    while (r < size) {
        min_dis = min(min_dis, pos[r] - pos[l]);
        bool move_l = true;
        auto &left = mp[pos[l]];
        for (int p: left) {
            if (cnt[p] == 1) {
                move_l = false;
                break;
            }
        }
        if (move_l) {
            for (int p: left) {
                cnt[p]--;
            }
            l++;
        } else {
            if (r == size - 1) {
                break;
            }
            r++;
            auto &right = mp[pos[r]];
            for (int p: right) {
                cnt[p]++;
            }
        }
    }
    cout << min_dis;
    return 0;
}