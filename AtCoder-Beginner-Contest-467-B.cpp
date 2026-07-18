#include <bits/stdc++.h>
using namespace std;

int n, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") {
            sum += b - a;
        }
    }
    cout << sum;
    return 0;
}
