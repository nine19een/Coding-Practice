#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e4 + 5;

int w, n, cnt;
vector<int> p(maxn);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.begin() + n);
    int l = 0, r = n - 1;
    while (l <= r) {
        cnt++;
        int sum = p[r--];
        if (l <= r && sum + p[l] <= w) {
            l++;
        }
    }
    cout << cnt;
}