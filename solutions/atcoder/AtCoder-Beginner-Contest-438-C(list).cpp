// Problem:  AtCoder Beginner Contest 438 C - 1D puyopuyo
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_c
// Author:   nine19een
// Date:     2025-12-30
// Method:   list

#include<bits/stdc++.h>
using namespace std;

list<int> l;
int n;

void delate(list<int>::iterator &it, int &cur, int &cnt) {
    int t = 4;
    while (t--) {
        it = l.erase(it);
        if (!t) {
            break;
        }
        it = prev(it);
    }
    cur = *it;
    cnt = 1;
    auto It = it--;
    t = 3;
    while (t--) {
        if (*it != cur) {
            it = It;
            break;
        } else {
            cnt++;
            if (it == l.begin() || cnt == 4) {
                it = It;
                break;
            }
            it--;
        }
    }
    if (cnt == 4) {
        delate(it, cur, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        l.push_back(a);
    }
    auto it = l.begin();
    int cnt = 0, cur_num = l.front();
    while (it != l.end()) {
        if (*it == cur_num) {
            cnt++;
            if (cnt == 4) {
                delate(it, cur_num, cnt);
            }
            it++;
        } else {
            cnt = 0;
            cur_num = *it;
        }
    }
    cout << l.size();
    return 0;
}
