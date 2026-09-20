// Problem:  AtCoder Beginner Contest 438 B - Substring 2
// Link:     https://atcoder.jp/contests/abc438/tasks/abc438_b
// Author:   nine19een
// Date:     2025-12-30

#include<bits/stdc++.h>
using namespace std;

int N, M, s[105], t[105];
string S, T;

void stTOnum(string &str, int arr[]) {
    int i = 0;
    for (char c: str) {
        arr[i++] = c - '0';
    }
}

int dif(int a, int b) {
    return a >= b ? a - b : a + 10 - b;
}

int cmpANDcnt() {
    int ans = INT_MAX;
    for (int i = 0; i <= N - M; ++i) {
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            sum += dif(s[i + j], t[j]);
        }
        ans = min(ans, sum);
    }
    return ans;
}

int main() {
    cin >> N >> M >> S >> T;
    stTOnum(S, s);
    stTOnum(T, t);
    cout << cmpANDcnt();
    return 0;
}
