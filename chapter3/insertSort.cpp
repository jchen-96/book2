#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr, int n) {
  for (int i = 0; i < n; i++) {
    if (i)
      cout << " ";
    cout << arr[i];
  }
  cout << endl;
  return;
}
void insertSort(vector<int>& arr, int n){
  for (int i = 1; i < n; i++) {
    int temp = arr[i];
    int j = i - 1;
    while(j>=0&&arr[j]>temp){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=temp;
  }
  return;
}

int main() {
  int n;
  cin>>n;
  vector<int> arr;
  int t;
  for(int i=0;i<n;i++){
    cin>>t;
    arr.push_back(t);
  }
  printArr(arr,n);
  insertSort(arr,n);
  printArr(arr,n);
  return 0;
}
