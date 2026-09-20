// Problem:  P1886 【模板】单调队列 / 滑动窗口
// Link:     https://www.luogu.com.cn/problem/P1886
// Author:   nine19een
// Date:     2025-12-09

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int n, k;
deque<int> min_q, max_q;
vector<int> a;

void find_min(int i, int x) {
    while (!min_q.empty() && a[min_q.back()] >= x) {
        min_q.pop_back();
    }
    min_q.push_back(i);
    if (i - min_q.front() + 1 > k) {
        min_q.pop_front();
    }
    if (i >= k - 1) {
        cout << a[min_q.front()] << " ";
    }
}

void find_max(int i, int x) {
    while (!max_q.empty() && a[max_q.back()] <= x) {
        max_q.pop_back();
    }
    max_q.push_back(i);
    if (i - max_q.front() + 1 > k) {
        max_q.pop_front();
    }
    if (i >= k - 1) {
        cout << a[max_q.front()] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a.reserve(MAXN);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        find_min(i, a[i]);
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        find_max(i, a[i]);
    }
    return 0;
}
