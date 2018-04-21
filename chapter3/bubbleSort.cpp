#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0, t = 0; i < n; i++) {
        cin >> t;
        arr.push_back(t);
    }
    int times = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < n - i) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                times++;
            }
            j++;
        }
    }

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << endl;
    cout << times<<endl;
    return 0;
}
