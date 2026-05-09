#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 2e5 + 5;

int n, l[maxn], c[maxn];
ll k;
unordered_map<int, int> mp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++) {
            int num;
            cin >> num;
            mp[i][j] = num;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    ll sum = 0, aim_idx = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1ll * c[i] * l[i];
        if (sum >= k) {
            sum -= 1ll * c[i] * l[i];
            aim_idx = i;
            break;
        }
    }
    ll r = k - sum;
    ll mod = r % l[aim_idx];
    if (!mod) {
        cout << mp[aim_idx][l[aim_idx]];
    } else {
        cout << mp[aim_idx][mod];
    }
    return 0;
}