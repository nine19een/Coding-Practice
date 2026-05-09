#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

int n, x, y;
unordered_map<int, int> mp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            int num;
            cin >> num;
            mp[i][j] = num;
        }
    }
    cin >> x >> y;
    cout << mp[x][y];
    return 0;
}