#include <iostream>
#include <algorithm>
#include <vector>
//打印出排序后的数组和交换的次数

using namespace std;

int main() {
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0,t=0;i<n;i++){
        cin>>t;
        arr.push_back(t);
    }
    int times=0;
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(i!=minIndex){
            swap(arr[i],arr[minIndex]);
            times++;
        }
    }
    for(int i=0;i<n;i++){
        if(i)
            cout<<" ";
        cout<<arr[i];
    }
    cout<<endl;
    cout<<times<<endl;


    return 0;
}
