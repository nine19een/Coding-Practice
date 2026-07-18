#include <bits/stdc++.h>
using namespace std;

int h, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    if (w * 10000 / h / h >= 25) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
