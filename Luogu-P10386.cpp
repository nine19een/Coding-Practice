// Problem:  Luogu P10386 [蓝桥杯 2024 省 A] 五子棋对弈
// Link:     https://www.luogu.com.cn/problem/P10386
// Author:   nine19een
// Date:     2025-09-25

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    int x, y;
};

Point p[30];
ll cnt_ans;
int cnt_chess;
int chessboard[10][10];

bool LineAndColumn() {
    int ans_line = 0, ans_column = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            ans_line += chessboard[i][j];
            ans_column += chessboard[j][i];
        }
        if (ans_line == 5 || ans_line == 0 || ans_column == 5 || ans_column == 0) {
            return false;
        }
        ans_line = 0, ans_column = 0;
    }
    return true;
}

bool Diagonal() {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= 5; i++) {
        ans1 += chessboard[i][i];
        ans2 += chessboard[i][6 - i];
    }
    if (ans1 == 0 || ans2 == 0 || ans1 == 5 || ans2 == 5) {
        return false;
    }
    return true;
}

bool isDraw() {
    return (LineAndColumn() && Diagonal());
}

void dfs(int idx, int cnt_chess) {
    if (25 - idx < (13 - cnt_chess)) {
        return;
    }
    if (cnt_chess == 13) {
        cnt_ans += (isDraw()) ? 1 : 0;
        return;
    }
    chessboard[p[idx + 1].x][p[idx + 1].y] = 1;
    dfs(idx + 1, cnt_chess + 1);
    chessboard[p[idx + 1].x][p[idx + 1].y] = 0;
    dfs(idx + 1, cnt_chess);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k = 0;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
           p[++k] = {i, j};
        }
    }
    int idx = 0;
    dfs(idx, cnt_chess);
    cout << cnt_ans << endl;
}
