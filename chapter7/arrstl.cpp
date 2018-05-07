#include <iostream>
#include <algorithm>
#include <vector>


//利用stl进行对数组进行排序,进行排序，sort为不稳定的排序，稳定的可以采用stable_sort

using namespace std;

int main(){
    int v[5];
    for(int i=0;i<5;i++){
        cin>>v[i];
    }

    sort(v,v+5);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}