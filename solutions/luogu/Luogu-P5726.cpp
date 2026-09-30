// Luogu P5726 【深基4.习9】打分
// https://www.luogu.com.cn/problem/P5726

#include <bits/stdc++.h>
using namespace std;

int n;
double score;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int sum = 0, max_s = -1, min_s = 11;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        max_s = max(max_s, s);
        min_s = min(min_s, s);
        sum += s;
    }
    sum -= max_s + min_s;
    score = 1.0 * sum / (n - 2);
    cout << fixed << setprecision(2) << score;
    return 0;
}