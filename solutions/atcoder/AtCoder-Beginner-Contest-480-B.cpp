// AtCoder Beginner Contest 480 B - Invalid Vote
// https://atcoder.jp/contests/abc480/tasks/abc480_b

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 105;

int n, m, cnt[maxn];
unordered_map<string, bool> vis;
unordered_map<string, int> id;

void CNT(string &s) {
    if (vis.count(s)) {
        cnt[id[s]]++;
        return;
    }
    int dif_person = 0, dif_id = 0;
    for (const pair<string, int> p: id) {
        string ns = p.first;
        if (ns.length() != s.length()) {
            continue;
        }
        int dif = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ns[i]) {
                dif++;
            }
        }
        if (dif == 1) {
            dif_person++;
            dif_id = p.second;
            if (dif_person > 1) {
                return;
            }
        }
    }
    if (dif_person == 1) {
        cnt[dif_id]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        vis[s] = true;
        id[s] = i;
    }
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        CNT(s);
    }
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << '\n';
    }
    return 0;
}
