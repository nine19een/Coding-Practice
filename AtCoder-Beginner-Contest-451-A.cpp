#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s.size() % 5) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}
