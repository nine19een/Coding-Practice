// Problem:  Luogu B2159 成绩排序
// Link:     https://www.luogu.com.cn/problem/B2159
// Author:   nine19een
// Date:     2025-11-18

#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int score;
};

int n;

int main() {
    cin >> n;
    vector<Student> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score;
    }
    sort(stu.begin(), stu.end(), [](const Student &a, const Student &b) {
        if (a.score != b.score) {
            return a.score > b.score;
        } else {
            return a.name < b.name;
        }
    });
    for (Student stu: stu) {
        cout << stu.name << " " << stu.score << endl;
    }
    return 0;
}
