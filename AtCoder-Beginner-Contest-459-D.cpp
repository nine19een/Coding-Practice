// Problem:  AtCoder Beginner Contest 459 D - Adjacent Distinct String
// Link:     https://atcoder.jp/contests/abc459/tasks/abc459_d
// Author:   nine19een
// Date:     2026-05-23

#include<bits/stdc++.h>
using namespace std;

struct Letter {
    int cnt;
    char c;

    bool operator<(const Letter &x) const {
        return cnt < x.cnt;
    }
};

string s;
int t;

void op() {
    string s;
    vector<int> cnt(30, 0);
    cin >> s;
    int len = (int) s.length();
    int max_cnt = 0;
    for (char c: s) {
        cnt[c - 'a']++;
        max_cnt = max(max_cnt, cnt[c - 'a']);
    }
    if (max_cnt > (len + 1) / 2) {
        cout << "No\n";
        return;
    }
    priority_queue<Letter> pq;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            pq.push({cnt[i], char(i + 'a')});
        }
    }
    string ans;
    while (!pq.empty()) {
        Letter p = pq.top();
        pq.pop();
        if (!ans.empty() && p.c == ans.back()) {
            Letter p2 = pq.top();
            pq.pop();
            ans += p2.c;
            if (p2.cnt != 1) {
                pq.push({p2.cnt - 1, p2.c});
            }
            pq.push(p);
            continue;
        }
        ans += p.c;
        if (p.cnt != 1) {
            pq.push({p.cnt - 1, p.c});
        }
    }
    cout << "Yes\n" << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        op();
    }
}
