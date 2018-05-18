#include <iostream>
#include <stack>
using namespace std;

static const int N=100;

static const int WHITE=0;

static const int GRAY=1;

static const int BLACK=2;





//用栈实现深度优先搜索


/**
 * color 标记访问状态的数组，
 * M[N][N] 邻接矩阵 如果存在定点i到顶点j的边，则M[i][j]=trul
 * Stack 栈，暂存访问过程中的顶点
**/
int n,M[N][N];
int color[N],d[N],f[N],tt;
int nt[N];


//按序号，获取和u相邻的v
int next(int u){
    for(int v=nt[u];v<n;v++){
        nt[u]=v+1;
        if(M[u][v]) return v;
    }
    return -1;
}

//用栈实现深度优先搜索
void dfs(int r){
    for(int i=0;i<n;i++) nt[i]=0;

    stack<int> S;
    S.push(r);
    color[r]=GRAY;
    d[r]=++tt;

    while(!S.empty()){
        int u=S.top();
        int v=next(u);

        if(v!=-1){
            if(color[v]==WHITE){
                color[v]=GRAY;
                d[v]=++tt;
                S.push(v);
            }
        }else{
            S.pop();
            color[u]=BLACK;
            f[u]=++tt;
        }
    }

}

void dfs(){
    //初始化
    for(int i=0;i<n;i++){
        color[i]=WHITE;
        nt[i]=0;
    }
    tt=0;

    for(int u=0;u<n;u++){
        if(color[u]==WHITE)
            dfs(u);
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
    }
    return;
}
int main(){
    int u,k,v;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>u>>k;

        u--;
        for(int i=0;i<k;i++){
            cin>>v;
            v--;
            M[u][v]=1;
        }
    }

    dfs();
    return 0;
}
