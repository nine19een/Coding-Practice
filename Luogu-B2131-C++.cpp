// Problem:  B2131 甲流病人初筛
// Link:     https://www.luogu.com.cn/problem/B2131
// Author:   nine19een
// Date:     2025-12-09

#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;

int n;
vector<string> patient;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string name;
        double temperature;
        bool cough;
        cin >> name >> temperature >> cough;
        if (temperature >= 37.5 && cough)
            patient.push_back(name);
    }
    for (string s: patient) {
        cout << s << endl;
    }
    cout << patient.size();
    return 0;
}
