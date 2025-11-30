// Problem:  Luogu P1830 轰炸III
// Link:     https://www.luogu.com.cn/problem/P1830
// Author:   nine19een
// Date:     2025-11-30

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;

struct Point {
    bool isBoom;
    int cnt, lastBoom;
};

Point p[maxn][maxn];
int n, m, x, y;

void Boom(int round, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            p[i][j].isBoom = true;
            p[i][j].cnt++;
            p[i][j].lastBoom = round;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= x; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Boom(i, x1, y1, x2, y2);
    }
    for (int i = 1; i <= y; i++) {
        int key_x, key_y;
        cin >> key_x >> key_y;
        if (p[key_x][key_y].isBoom) {
            cout << "Y " << p[key_x][key_y].cnt << " " << p[key_x][key_y].lastBoom << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
