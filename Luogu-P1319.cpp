// Problem:  Luogu P1319 压缩技术
// Link:     https://www.luogu.com.cn/problem/P1319
// Author:   nine19een
// Date:     2025-11-28

#include<bits/stdc++.h>
using namespace std;

int n, sum = 0, cnt;
bool zero;
vector<int> v;

void print(int x) {
    for (int i = 1; i <= x; ++i) {
        if (++cnt > n) {
            cout << endl;
            cnt = 1;
        }
        cout << zero;
    }
}

int main() {
    cin >> n;
    int N = n * n;
    while (sum != N) {
        int num;
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    for (int p : v) {
        print(p);
        zero ^= true;
    }
    return 0;
}