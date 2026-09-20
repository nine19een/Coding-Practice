// Problem:  Luogu B3968 [GESP202403 五级] 成绩排序
// Link:     https://www.luogu.com.cn/problem/B3968
// Author:   nine19een
// Date:     2025-12-16

#include<stdio.h>
#define MAXN 10005

typedef struct {
    int ch, ma, en, tot, id, rank;
} Score;

int n;
Score s[MAXN];

int max(int a, int b) {
    return a > b ? a : b;
}

void swap(Score *ptr_a, Score *ptr_b) {
    Score c = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = c;
}

void bubble_sort_score(Score s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j].tot != s[j + 1].tot) {
                if (s[j].tot < s[j + 1].tot) {
                    swap(&s[j], &s[j + 1]);
                }
                continue;
            } else if (s[j].ch + s[j].ma != s[j + 1].ch + s[j + 1].ma) {
                if (s[j].ch + s[j].ma < s[j + 1].ch + s[j + 1].ma) {
                    swap(&s[j], &s[j + 1]);
                }
                continue;
            } else if (max(s[j].ch, s[j].ma) != max(s[j + 1].ch, s[j + 1].ma)) {
                if (max(s[j].ch, s[j].ma) < max(s[j + 1].ch, s[j + 1].ma)) {
                    swap(&s[j], &s[j + 1]);
                }
                continue;
            }
        }
    }
}

void bubble_sort_idx(Score s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j].id > s[j + 1].id) {
                swap(&s[j], &s[j + 1]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[i].ch, &s[i].ma, &s[i].en);
        s[i].tot = s[i].ch + s[i].ma + s[i].en;
        s[i].id = i;
    }
    bubble_sort_score(s, n);
    s[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (s[i].tot == s[i - 1].tot && s[i].ch + s[i].ma == s[i - 1].ch + s[i - 1].ma && max(s[i].ch, s[i].ma) == max(
                s[i - 1].ch, s[i - 1].ma)) {
            s[i].rank = s[i - 1].rank;
        } else {
            s[i].rank = i + 1;
        }
    }
    bubble_sort_idx(s, n);
    for (Score *score = s; score < s + n; score++) {
        printf("%d\n", score->rank);
    }
    return 0;
}
