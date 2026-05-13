// Problem:  Luogu P7113 [NOIP2020] 排水系统
// Link:     https://www.luogu.com.cn/problem/P7113
// Author:   nine19een
// Date:     2025-11-05

#include<bits/stdc++.h>
using namespace std;
using ll = __int128_t;
int const maxn = 1e5 + 5;

struct Fraction {
    ll son, mom = 1;
};

struct Node {
    int indegree, outdegree;
    Fraction val;
    vector<ll> adj;
};

int n, m;
Node node[maxn];
vector<int> ans;

void print(ll x) {
    string s;
    while (x != 0) {
        s += x % 10 + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void cancelling(int idx) {
    ll gcd_num = gcd(node[idx].val.mom, node[idx].val.son);
    node[idx].val.mom /= gcd_num;
    node[idx].val.son /= gcd_num;
}

void division(int idx) {
    ll gcd_num = gcd(node[idx].outdegree, node[idx].val.son);
    node[idx].outdegree /= gcd_num;
    node[idx].val.son /= gcd_num;
    node[idx].val.mom *= node[idx].outdegree;
}

void sum(int sum_idx, int aim_idx) {
    ll lcm_num = lcm(node[aim_idx].val.mom, node[sum_idx].val.mom);
    node[aim_idx].val.son = node[aim_idx].val.son * (lcm_num / node[aim_idx].val.mom) + node[sum_idx].val.son * (lcm_num / node[sum_idx].val.mom);
    node[aim_idx].val.mom = lcm_num;
    cancelling(aim_idx);
}

void BFS() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (node[i].adj.empty()) {
            ans.push_back(i);
        }
        if (!node[i].indegree) {
            node[i].val.son = 1, node[i].val.mom = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (node[u].outdegree) {
            division(u);
        }
        for (int p : node[u].adj) {
            sum(u, p);
            node[p].indegree--;
            if (!node[p].indegree) {
                q.push(p);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ans.reserve(maxn);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].outdegree;
        for (int j = 1; j <= node[i].outdegree; ++j) {
            int idx;
            cin >> idx;
            node[i].adj.push_back(idx);
            node[idx].indegree += 1;
        }
    }
    BFS();
    for (int p : ans) {
        print(node[p].val.son);
        cout << " ";
        print(node[p].val.mom);
        cout << '\n';
    }
    return 0;
}