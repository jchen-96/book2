#include<iostream>
using namespace std;
static const int MAX=100;
static const int INFTY=(1<<21);
static const int white=0;
static const int gray=1;
static const int black=2;

//采用prim算法最小生成树


int n,M[MAX][MAX];

int prim(){
    int u,minv;
    int d[MAX],p[MAX],color[MAX];
    for(int i=0;i<n;i++){
	d[i]=INFTY;
	p[i]=-1;
	color[i]=white;
    }
    d[0]=0;
    while(1){
	minv=INFTY;
	u=-1;
	for(int i=0;i<n;i++){
	    if(minv>d[i]&&color[i]!=black){
		u=i;
		minv=d[i];
	    }
	}
	if(u==-1)break;
	color[u]=black;
	for(int v=0;v<n;v++){
	    if(color[v]!=black&&M[u][v]!=INFTY){
		if(d[v]>M[u][v]){
		    d[v]=M[u][v];
		    p[v]=u;
		    color[v]=gray;
		}
	    }
	}
    }

    int sum=0;
    for(int i=0;i<n;i++){
	if(p[i]!=-1)
	    sum+=M[i][p[i]];
    }

    return sum;

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    int e;
	    cin>>e;
	    M[i][j]=(e==-1)?INFTY:e;
	}
    }
    cout<<prim()<<endl;
    return 0;
}
