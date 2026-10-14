// Luogu P1104 生日
// https://www.luogu.com.cn/problem/P1104

#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int y, m, d, id;
};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<Student> st(n);
    for (int i = 0; i < n; ++i) {
        cin >> st[i].name >> st[i].y >> st[i].m >> st[i].d;
        st[i].id = i;
    }
    sort(st.begin(), st.end(), [](const Student &a, const Student &b) {
        if (a.y != b.y) {
            return a.y < b.y;
        }
        if (a.m != b.m) {
            return a.m < b.m;
        }
        if (a.d != b.d) {
            return a.d < b.d;
        }
        return a.id > b.id;
    });
    for (Student s: st) {
        cout << s.name << '\n';
    }
    return 0;
}
