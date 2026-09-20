// Problem:  Luogu P1157 组合的输出
// Link:     https://www.luogu.com.cn/problem/P1157
// Author:   nine19een
// Date:     2025-10-14

#include<bits/stdc++.h>
using namespace std;
int const maxn = 26;

int n, r;
vector<int> a;

void DFS(int idx, vector<int> &a) {
    if (idx > r) {
        for (int p : a) {
            cout << setw(3) << p;
        }
        cout << endl;
        return;
    }
    for (int i = (a.empty()) ? 1 : a.back() + 1; i <= n; ++i) {
        a.push_back(i);
        DFS(idx + 1, a);
        a.pop_back();
    }
}

int main() {
    cin >> n >> r;
    a.reserve(maxn);
    DFS(1, a);
    return 0;
}