// Problem:  AtCoder Beginner Contest 462 C - Not Covered Points
// Link:     https://atcoder.jp/contests/abc462/tasks/abc462_c
// Author:   nine19een
// Date:     2026-06-13

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e5 + 5;

struct Node {
    int x, y;

    bool operator<(const Node &other) const {
        return x < other.x;
    }
};

int n, c[maxn], ans;
vector<Node> node;

inline int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i]++;
    }
}

int query(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int nx, ny;
        cin >> nx >> ny;
        node.push_back({nx, ny});
    }
    sort(node.begin(), node.end());
    for (Node nd: node) {
        int cur_y = nd.y;
        if (!query(cur_y)) {
            ans++;
        }
        add(cur_y);
    }
    cout << ans;
    return 0;
}
