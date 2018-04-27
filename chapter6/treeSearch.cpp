#include <iostream>


using namespace std;

int n,A[50];


int slove(int i,int m){
    if(m==0) return 1;
    if(i>=n) return 0;
    int res=slove(i+1,m)||slove(i+1,m-A[i]);
    return res;
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int value;
        cin>>value;
        if(slove(0,value)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
