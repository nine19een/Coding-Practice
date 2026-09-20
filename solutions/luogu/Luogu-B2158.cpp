// Problem:  Luogu B2158 谁考了第 k 名
// Link:     https://www.luogu.com.cn/problem/B2158
// Author:   nine19een
// Date:     2025-11-19

#include<bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    double score;
};

int n, check_idx;
vector<Student> stu;

int main() {
    cin >> n >> check_idx;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.id >> s.score;
        stu.push_back(s);
    }
    sort(stu.begin(), stu.end(), [](const Student &a, const Student &b) {
        return a.score > b.score;
    });
    cout << stu[check_idx - 1].id << " " << stu[check_idx - 1].score;
    return 0;
}