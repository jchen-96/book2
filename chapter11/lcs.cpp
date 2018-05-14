#include <iostream>
#include <string>
#include <algorithm>

//求两个字符串的最长公共子串

using namespace std;


static const int N = 1000;


int lcs(string x, string y) {
    int c[N + 1][N + 1];
    int m = x.size();
    int n = y.size();
    int res = 0;

    x = ' ' + x;
    y = ' ' + y;

    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int i = 0; i <= n; i++) c[0][i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
            }
            res = max(res, c[i][j]);
        }
    }

    return res;
}

int main() {
    string s1, s2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}