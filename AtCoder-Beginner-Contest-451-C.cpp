#include <bits/stdc++.h>
using namespace std;
constexpr int maxQ = 3e5 + 5;

int Q;
multiset<int> ms;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Q;
    while (Q--) {
        int q, h;
        cin >> q >> h;
        if (q == 1) {
            ms.insert(h);
            cout << ms.size() << '\n';
        } else {
            auto it = ms.upper_bound(h);
            ms.erase(ms.begin(), it);
            cout << ms.size() << '\n';
        }
    }
    return 0;
}
