// Problem:  Luogu P1121 环状最大两段子段和
// Link:     https://www.luogu.com.cn/problem/P1121
// Author:   nine19een
// Date:     2025-11-02

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll const maxn = 2e5 + 5;

int n;
ll total_a, a[maxn], max_L_to_R[maxn], dp_max_L_to_R[maxn], max_R_to_L[maxn], dp_max_R_to_L[maxn], min_L_to_R[maxn], dp_min_L_to_R[maxn], min_R_to_L[maxn], dp_min_R_to_L[maxn];

void find_L_to_R() {
    ll max_val = LLONG_MIN, min_val = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        dp_max_L_to_R[i] = max(dp_max_L_to_R[i - 1] + a[i], a[i]);
        max_val = max(max_val, dp_max_L_to_R[i]);
        max_L_to_R[i] = max_val;
        dp_min_L_to_R[i] = min(dp_min_L_to_R[i - 1] + a[i], a[i]);
        min_val = min(min_val, dp_min_L_to_R[i]);
        min_L_to_R[i] = min_val;
    }
}

void find_R_to_L() {
    ll max_val = LLONG_MIN, min_val = LLONG_MAX;
    for (int i = n; i >= 1; --i) {
        dp_max_R_to_L[i] = max(dp_max_R_to_L[i + 1] + a[i], a[i]);
        max_val = max(max_val, dp_max_R_to_L[i]);
        max_R_to_L[i] = max_val;
        dp_min_R_to_L[i] = min(dp_min_R_to_L[i + 1] + a[i], a[i]);
        min_val = min(min_val, dp_min_R_to_L[i]);
        min_R_to_L[i] = min_val;
    }
}

ll case_1() {
    ll max_val = LLONG_MIN;
    for (int i = 1; i < n; ++i) {
        max_val = max(max_val, max_L_to_R[i] + max_R_to_L[i + 1]);
    }
    return max_val;
}

ll case_2() {
    ll min_val = LLONG_MAX;
    for (int i = 1; i < n; ++i) {
        min_val = min(min_val, min_L_to_R[i] + min_R_to_L[i + 1]);
    }
    return total_a == min_val ? LLONG_MIN : total_a - min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        total_a += a[i];
    }
    find_L_to_R();
    find_R_to_L();
    cout << max(case_1(), case_2());
    return 0;
}
