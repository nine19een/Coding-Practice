// Problem:  Luogu P2196 [NOIP 1996 提高组] 挖地雷
// Link:     https://www.luogu.com.cn/problem/P2196
// Author:   nine19een
// Date:     2025-11-20
// Method:   拓扑排序+DP

#include<bits/stdc++.h>
using namespace std;
int const maxn = 25;

struct Node {
    int indegree, outdegree, val, dp;
    vector<int> adj;
};

int n, max_dp = INT_MIN, ans_idx, ans_path[maxn];
Node cellar[maxn];

void makeADJ() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool isConnected;
            cin >> isConnected;
            if (isConnected) {
                cellar[i].outdegree++;
                cellar[j].indegree++;
                cellar[i].adj.push_back(j);
            }
        }
    }
}

void BFS() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!cellar[i].indegree) {
            q.push(i);
            cellar[i].dp = cellar[i].val;
        }
        if (!cellar[i].outdegree) {
            ans_idx = max_dp <= cellar[i].dp ? i : ans_idx;
            max_dp = max(max_dp, cellar[i].dp);
        }
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int idx : cellar[front].adj) {
            cellar[idx].indegree--;
            if (cellar[idx].dp < cellar[idx].val + cellar[front].dp) {
                cellar[idx].dp = cellar[idx].val + cellar[front].dp;
                ans_path[idx] = front;
            }
            if (!cellar[idx].indegree) {
                q.push(idx);
            }
            if (!cellar[idx].outdegree) {
                ans_idx = max_dp <= cellar[idx].dp ? idx : ans_idx;
                max_dp = max(max_dp, cellar[idx].dp);
            }
        }
    }
}

void outputPath(int idx) {
    if (ans_path[idx]) {
        outputPath(ans_path[idx]);
    }
    cout << idx << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cellar[i].val;
    }
    makeADJ();
    BFS();
    outputPath(ans_idx);
    cout << '\n' << max_dp;
    return 0;
}