// Problem:  Luogu P1540 [NOIP 2010 提高组] 机器翻译
// Link:     https://www.luogu.com.cn/problem/P1540
// Author:   nine19een
// Date:     2025-12-08
// Method:   unordered_set + queue

#include<bits/stdc++.h>
using namespace std;

queue<int> q;
unordered_set<int> s;
int m, n, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!s.count(num)) {
            cnt++;
            q.push(num);
            s.insert(num);
            if (s.size() > m) {
                s.erase(q.front());
                q.pop();
            }
        }
    }
    cout << cnt;
    return 0;
}
