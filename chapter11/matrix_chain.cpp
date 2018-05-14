#include <iostream>
#include <algorithm>
using namespace std;

static const int N=100;

//求解矩阵链乘法的最优解
//p 用于存储矩阵的行和列的
//dp[i][j] 表示从矩阵i乘到矩阵j的最小乘法次数

int main(){
    int n;
    int p[N+1],dp[N+1][N+1];

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i-1]>>p[i];
    }

    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            dp[i][j]=(1<<21);//取一个很大的值
            for(int k=i;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }

    cout<<dp[1][n]<<endl;

    return 0;
}
