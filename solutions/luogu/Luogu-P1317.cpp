// Problem:  Luogu P1317 低洼地
// Link:     https://www.luogu.com.cn/problem/P1317
// Author:   nine19een
// Date:     2025-11-25

#include<bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    bool isSlope = false;
    int pre_height = 0, cur_height;
    for (int i = 1; i < n; i++) {
        cin >> cur_height;
        if (cur_height > pre_height && isSlope) {
            cnt++;
            isSlope = false;
        }
        if (cur_height < pre_height) {
            isSlope = true;
        }
        pre_height = cur_height;
    }
    cout << cnt;
    return 0;
}