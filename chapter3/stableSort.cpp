#include <iostream>
#include <vector>

// 给卡牌排序，判断冒泡排序和选择排序是否是稳定的排序，通过对比冒泡的结果和选择的排序结果可以判断选择排序是否为稳定的排序算法

using namespace std;

struct Card { char suit, value; };

void bubble(vector<Card> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int j=1;
    while(j<n-i){
      if(arr[j].value<arr[j-1].value){
        Card t = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = t;
      }
        j++;
    }
  }
  return;
}

void selectSort(vector<Card> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i; j < n; j++) {
      if (arr[j].value < arr[minIndex].value) {
        minIndex = j;
      }
    }
    Card t=arr[i];
    arr[i]=arr[minIndex];
    arr[minIndex]=t;
  }
  return;
}

void printArr(vector<Card> arr,int n){
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<arr[i].suit<<arr[i].value;
  }
  cout<<endl;
  return;
}

bool isStable(vector<Card> arr1,vector<Card> arr2,int n){
  for(int i=0;i<n;i++){
    if(arr1[i].suit!=arr2[i].suit){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  vector<Card> arr1,arr2;
  cin>>n;
  for(int i=0;i<n;i++){
    Card t;
    cin>>t.suit;
    cin>>t.value;
    arr1.push_back(t);
    arr2.push_back(t);
  }

  bubble(arr1,n);
  selectSort(arr2,n);
  printArr(arr1,n);
  cout<<"Stable"<<endl;
  printArr(arr2,n);
  if(isStable(arr1,arr2,n)){
    cout<<"Stable"<<endl;
  }else{
    cout<<"Not stable"<<endl;
  }

  return 0;
}
