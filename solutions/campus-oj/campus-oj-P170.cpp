// Campus OJ P170 最佳成绩时间轴
// https://oj.nine19een.com/#library/P170

#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 5;

struct Record {
    int id, score, t;
};

int n;
vector<Record> r, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    r.reserve(maxn);
    b.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id, score, t;
        cin >> id >> score >> t;
        r.push_back({id, score, t});
    }
    sort(r.begin(), r.end(), [](const Record &a, const Record &b) {
        if (a.id != b.id) {
            return a.id < b.id;
        }
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.t < b.t;
    });
    int cur = 0;
    for (auto p: r) {
        if (p.id != cur) {
            b.push_back(p);
        }
        cur = p.id;
    }
    sort(b.begin(), b.end(), [](const Record &a, const Record &b) {
        if (a.t != b.t) {
            return a.t < b.t;
        }
        return a.id < b.id;
    });
    cout << b.size() << '\n';
    for (auto p: b) {
        cout << p.id << " " << p.score << " " << p.t << '\n';
    }
    return 0;
}
