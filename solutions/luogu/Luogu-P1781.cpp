// Luogu P1781 宇宙总统
// https://www.luogu.com.cn/problem/P1781

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 25;

struct President {
    string score;
    int id;
};

int n;
vector<President> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    v.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        v.push_back({s, i});
    }
    sort(v.begin(), v.end(), [](const President &a, const President &b) {
        if (a.score.length() != b.score.length()) {
            return a.score.length() > b.score.length();
        }
        return a.score > b.score;
    });
    cout << v.front().id << '\n' << v.front().score;
    return 0;
}
