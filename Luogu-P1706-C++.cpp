// Problem:  Luogu P1706 全排列问题
// Link:     https://www.luogu.com.cn/problem/P1706
// Author:   nine19een
// Date:     2025-10-13

#include<bits/stdc++.h>
using namespace std;
int const maxn = 15;

int n;
bool vis[maxn];
vector<int> ans;

void DFS(int idx) {
    if (idx > n) {
        for (int i = 0; i < n; ++i) {
            cout << setw(5) << ans[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            ans.push_back(i);
            DFS(idx + 1);
            vis[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    ans.reserve(maxn);
    cin >> n;
    DFS(1);
    return 0;
}