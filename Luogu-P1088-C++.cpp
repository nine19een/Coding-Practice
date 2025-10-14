// Problem:  P1088 [NOIP 2004 普及组] 火星人
// Link:     https://www.luogu.com.cn/problem/P1088
// Author:   nine19een
// Date:     2025-10-14

#include<bits/stdc++.h>
using namespace std;
int const maxn = 1e4 + 5;

int n, m, cnt, a[maxn];
bool vis[maxn], quit;
vector<int> ans;

void DFS(int idx, vector<int> &ans) {
    if (idx > n) {
        cnt++;
        if (cnt == m + 1) {
            for (int p : ans) {
                cout << p << " ";
            }
            quit = true;
        }
        return;
    }
    for (int i = (!cnt) ? a[idx] : 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            ans.push_back(i);
            DFS(idx + 1, ans);
            if (quit) {
                return;
            }
            vis[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    ans.reserve(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    DFS(1, ans);
    return 0;
}