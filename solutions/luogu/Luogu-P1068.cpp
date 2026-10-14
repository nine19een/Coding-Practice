// Luogu P1068 [NOIP 2009 普及组] 分数线划定
// https://www.luogu.com.cn/problem/P1068

#include <bits/stdc++.h>
using namespace std;

struct Student {
    int k, s;
};

int n, m, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<Student> s(n);
    m *= 1.5;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].k >> s[i].s;
    }
    sort(s.begin(), s.end(), [](const Student &a, const Student &b) {
        if (a.s != b.s) {
            return a.s > b.s;
        }
        return a.k < b.k;
    });
    int lim = s[m - 1].s;
    for (auto stu: s) {
        if (stu.s < lim) {
            break;
        }
        cnt++;
    }
    cout << lim << " " << cnt << '\n';
    for (int i = 0; i < cnt; ++i) {
        cout << s[i].k << " " << s[i].s << '\n';
    }
    return 0;
}
