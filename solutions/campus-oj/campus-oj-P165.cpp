// Campus OJ P165 题目上架
// https://oj.nine19een.com/#library/P165

#include<bits/stdc++.h>
using namespace std;

int a, b, c, n, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            a++;
        } else if (op == 2 && a) {
            a--;
            b++;
        } else if (op == 3 && b) {
            b--;
            c++;
        } else if (op == 4 && a) {
            a--;
        } else {
            cnt++;
        }
    }
    cout << c << " " << a + b << " " << cnt;
    return 0;
}
