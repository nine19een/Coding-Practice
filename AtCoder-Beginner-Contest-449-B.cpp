#include <bits/stdc++.h>
using namespace std;

int h, w, q;

void Q1(int x) {
    cout << x * w << '\n';
    h -= x;
}

void Q2(int x) {
    cout << x * h << '\n';
    w -= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> q;
    for (int i = 1; i <= q; i++) {
        int num, x;
        cin >> num >> x;
        if (num == 1) {
            Q1(x);
        } else {
            Q2(x);
        }
    }
    return 0;
}