// Problem:  Luogu B2125 最高分数的学生姓名
// Link:     https://www.luogu.com.cn/problem/B2125
// Author:   nine19een
// Date:     2025-11-17

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

struct student {
    int score;
    string name;
};

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<student> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].score >> stu[i].name;
    }
    sort(stu.begin(), stu.end(), [](const student &a, const student &b) {
        return a.score > b.score;
    });
    cout << stu.front().name;
    return 0;
}
