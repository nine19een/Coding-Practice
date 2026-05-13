// Problem:  Luogu P5740 【深基7.例9】最厉害的学生
// Link:     https://www.luogu.com.cn/problem/P5740
// Author:   nine19een
// Date:     2025-12-16

#include<stdio.h>
#define MAXN 1005

typedef struct {
    char name[10];
    int ch, ma, en;
} Student;

int n;
Student stu[MAXN];

Student *findBest(Student stu[], int n) {
    Student *best = &stu[0];
    for (int i = 0; i < n; i++) {
        best = stu[i].ch + stu[i].ma + stu[i].en > best->ch + best->ma + best->en ? &stu[i] : best;
    }
    return best;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", stu[i].name, &stu[i].ch, &stu[i].ma, &stu[i].en);
    }
    Student *ans = findBest(stu, n);
    printf("%s %d %d %d", ans->name, ans->ch, ans->ma, ans->en);
    return 0;
}
