// Problem:  P1093 [NOIP 2007 普及组] 奖学金
// Link:     https://www.luogu.com.cn/problem/P1093
// Author:   nine19een
// Date:     2025-12-09

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;

struct Student {
    int id, ch, ma, en, tot;
};

int n;
vector<Student> stu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stu.reserve(MAXN);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int ch, ma, en;
        cin >> ch >> ma >> en;
        Student s = {i, ch, ma, en, ch + ma + en};
        stu.push_back(s);
    }
    sort(stu.begin(), stu.end(), [](const Student &a, const Student &b) {
        if (a.tot != b.tot) {
            return a.tot > b.tot;
        } else if (a.ch != b.ch) {
            return a.ch > b.ch;
        } else {
            return a.id < b.id;
        }
    });
    for (int i = 0; i < 5; i++) {
        cout << stu[i].id << " " << stu[i].tot << '\n';
    }
    return 0;
}
