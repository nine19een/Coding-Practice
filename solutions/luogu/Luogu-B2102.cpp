// Problem:  Luogu B2102 计算鞍点
// Link:     https://www.luogu.com.cn/problem/B2102
// Author:   nine19een
// Date:     2025-11-13

#include<bits/stdc++.h>
using namespace std;

int a[10][10], max_line[10], min_row[10];

int main() {
    for (int i = 1; i <= 5; ++i) {
        max_line[i] = INT_MIN;
        min_row[i] = INT_MAX;
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            cin >> a[i][j];
            max_line[i] = max(max_line[i], a[i][j]);
            min_row[j] = min(min_row[j], a[i][j]);
        }
    }
    bool flag = false;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if ((a[i][j] == max_line[i]) && (a[i][j] == min_row[j])) {
                cout << i << " " << j << " " << a[i][j];
                flag = true;
            }
        }
    }
    if (!flag) {
        cout << "not found";
    }
    return 0;
}
