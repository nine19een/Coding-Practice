// Problem:  Luogu P11199 [JOIG 2024] ダンス / Dance
// Link:     https://www.luogu.com.cn/problem/P11199
// Author:   nine19een
// Date:     2025-11-27

#include<bits/stdc++.h>
using namespace std;

int n, d;

int main() {
    cin >> n >> d;
    int N = 2 * n;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i += 2) {
        if (abs(a[i] - a[i + 1]) > d) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
