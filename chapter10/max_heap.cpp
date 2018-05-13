#include <iostream>

using namespace std;

#define MAX 2000000

int H, A[MAX + 1];


void maxHeapify(int i) {
    int l, r, target;

    l = 2 * i;
    r = 2 * i + 1;

    //从左子节点，自身，右子节点中选出最大的节点值
    if (l <= H && A[l] > A[i])
        target = l;
    else
        target = i;

    if (r <= H && A[target] < A[r])
        target = r;


    if (target != i) {
        swap(A[i], A[target]);
        maxHeapify(target);
    }
}

int main() {
    cin >> H;
    for (int i = 1; i <= H; i++) {
        cin >> A[i];
    }

    for (int i = H / 2; i >= 1; i--)
        maxHeapify(i);

    for (int i = 1; i <= H; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}