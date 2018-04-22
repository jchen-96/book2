// 关键在于理解题意，货物以此装，所以不是背包问题．采用二分查找，对p进行搜索
#include <iostream>

using namespace std;

#define Max 100000

typedef long long llong;

int n, k;
llong T[Max];

int check(llong p) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        long s = 0;
        while (s + T[i] <= p) {
            s += T[i];
            i++;
            if (i == n) {
                return n;
            }
        }
    }
    return i;
}

int slove() {
    llong left = 0;
    llong right = 100000 * 10000;

    int mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        int v = check(mid);
        if (v >= n) {
            right = mid;
        } else left = mid;
    }

    return right;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    llong ans = slove();
    cout << ans << endl;
}
