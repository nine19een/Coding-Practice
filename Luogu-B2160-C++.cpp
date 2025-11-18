// Problem:  Luogu B2160 病人排队
// Link:     https://www.luogu.com.cn/problem/B2160
// Author:   nine19een
// Date:     2025-11-17

#include<bits/stdc++.h>
using namespace std;
int const maxn = 105;

struct Patient {
    string id;
    int age;
};

int n;
vector<Patient> old;
vector<string> others;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    old.reserve(maxn);
    others.reserve(maxn);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        Patient p;
        cin >> p.id >> p.age;
        if (p.age >= 60) {
            old.push_back(p);
        } else {
            others.push_back(p.id);
        }
    }
    stable_sort(old.begin(), old.end(), [](const Patient &p1, const Patient &p2) {
        return p1.age > p2.age;
    });
    for (Patient p: old) {
        cout << p.id << endl;
    }
    for (string s: others) {
        cout << s << endl;
    }
    return 0;
}
