#include <bits/stdc++.h>
using namespace std;

int a[105], n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cout << a[x];
    return 0;
}