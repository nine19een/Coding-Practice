#include <bits/stdc++.h>
using namespace std;
constexpr int maxm = 105;

int n, m, now[maxm], next_term[maxm];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        now[a]++;
        next_term[b]++;
    }
    for (int i = 1; i <= m; ++i) {
        cout << next_term[i] - now[i] << '\n';
    }
    return 0;
}
