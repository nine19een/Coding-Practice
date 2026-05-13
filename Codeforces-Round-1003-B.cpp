// Problem:  Codeforces Round 1003 B. Skibidus and Ohio
// Link:     https://codeforces.com/contest/2065/problem/B
// Author:   nine19een
// Date:     2025-07-24

#include <bits/stdc++.h>
using namespace std;
int n;
char word[105][105];

void DELETE(char w[]) {
    int size = strlen(w);
    if (size == 1) {
        cout << 1 << endl;
        return;
    }
    for(int i = 0; i < size - 1; i++) {
        if (w[i] == w[i + 1]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << size << endl;
    return;
}

int main() {
    memset (word, 0, sizeof(word));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> word[i];
    }
    for (int i = 1; i <= n; i++) {
        DELETE(word[i]);
    }
    return 0;
}
