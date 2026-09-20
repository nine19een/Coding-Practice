// Problem:  Luogu P10497 [USACO03OPEN] Lost Cows
// Link:     https://www.luogu.com.cn/problem/P10497
// Author:   nine19een
// Date:     2025-08-12

#include <bits/stdc++.h>
using namespace std;

int n, b[8005], c[8005], ans[8005];

int Lowbit(int num) {
    return num & (num ^ (num - 1));
}

int Query(int num) {
    int ans = 0;
    for (int i = num; i != 0; i -= Lowbit(i)) {
        ans += c[i];
    }
    return ans;
}

void Change(int num, int n) {
    for (int i = num; i <= n; i += Lowbit(i)) {
        c[i] -= 1;
    }
}

void Search(int num, int n) {
    int left = 1, right = n, ans_idx;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (b[num] == Query(middle) - 1) {
            ans_idx = middle;
            right = middle - 1;
        } else if (b[num] < Query(middle) - 1) {
            right = middle - 1;
        } else if (b[num] > Query(middle) - 1) {
            left = middle + 1;
        }
    }
    ans[num] = ans_idx;
    Change(ans_idx, n);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        c[i] = 1 + Query(i - 1) - Query(i - Lowbit(i));
        if (i >= 2) {
            cin >> b[i];
        }
        b[1] = 0;
    }
    for (int i = n; i >= 1; i--) {
        Search(i, n);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
