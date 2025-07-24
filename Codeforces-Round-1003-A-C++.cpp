// Problem:  Codeforces Round 1003 A. Skibidus and Amog'u
// Link:     https://codeforces.com/contest/2065/problem/A
// Author:   nine19een
// Date:     2025-07-24

#include <bits/stdc++.h>
using namespace std;

void TRANSLATE(char w[]) {
    int size = strlen(w);
    w[size - 1] = 0;
    w[size-2] = 'i';
    cout << w << endl;
    return;
}

int n;
char words[105][15];
int main() {
    memset(words, 0, sizeof(words));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }
    for (int i = 1; i <= n; i++) {
        TRANSLATE(words[i]);
    }
    return 0;
}