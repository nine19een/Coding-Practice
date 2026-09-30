// Luogu P1205 [USACO1.2] 方块转换 Transformations
// https://www.luogu.com.cn/problem/P1205

#include <bits/stdc++.h>
using namespace std;
using matrix = vector<string>;

int n;
matrix a, aim, cur;

void read(matrix &mat) {
    mat.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
}

bool match() {
    return cur == aim;
}

void rotate90() {
    matrix temp = cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cur[j][n - i - 1] = temp[i][j];
        }
    }
}

void flip() {
    matrix temp = a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cur[i][n - j - 1] = temp[i][j];
        }
    }
}

int solve_num() {
    int num = 0;
    cur = a;
    if (match()) {
        num = 6;
    }
    rotate90();
    if (match()) {
        return 1;
    }
    rotate90();
    if (match()) {
        return 2;
    }
    rotate90();
    if (match()) {
        return 3;
    }
    flip();
    if (match()) {
        return 4;
    }
    int t = 3;
    while (t--) {
        rotate90();
        if (match()) {
            return 5;
        }
    }
    return num ? num : 7;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    read(a);
    read(aim);
    cout << solve_num();
    return 0;
}