#include <iostream>
#include <algorithm>

#define MAX 10000
#define NIL -1
//答打印二叉树的结点信息，父节点，兄弟结点，子节点数目，深度，高度，结点类型
using namespace std;


struct Node {
    int partent, left, right;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
    if (u == NIL) return;

    D[u] = d;

    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHight(T[u].left) + 1;
    }
    if (T[u].right != NIL) {
        h2 = setHight(T[u].right) + 1;
    }
    return H[u] = max(h1, h2);
}


//返回节点u的兄弟节点

int getBrother(int u) {
    if (T[u].partent == NIL) {
        return NIL;
    }
    if (T[T[u].partent].left != u && T[T[u].partent].left != NIL) {
        return T[T[u].partent].left;
    }
    if (T[T[u].partent].right != u && T[T[u].partent].right != NIL) {
        return T[T[u].partent].right;
    }

    return NIL;

}

void print(int u) {
    cout << "node " << u << ": " << "parent = "<<T[u].partent<<", "<<"sibling = "<<getBrother(u)<<", ";
    int deg=0;
    if(T[u].left!=NIL)
        deg++;
    if(T[u].right!=NIL)
        deg++;
    cout<<"degree = "<<deg<<", "<<"depth = "<<D[u]<<", height = "<<H[u]<<", ";
    if(T[u].partent==NIL){
        cout<<"root";
    }else if(T[u].left==NIL&&T[u].right==NIL){
        cout<<"leaf";
    }else{
        cout<<"internal node";
    }
    cout<<endl;
}

int main(){
    int v,l,r,root=0;
    cin>>n;
    for(int i=0;i<n;i++){
        T[i].partent=NIL;
    }
    for(int i=0;i<n;i++){
        cin>>v>>l>>r;
        T[v].left=l;
        T[v].right=r;
        if(l!=NIL) T[l].partent=v;
        if(r!=NIL) T[r].partent=v;
    }

    for(int i=0;i<n;i++){
        if(T[i].partent==NIL)
            root=i;
    }

    setDepth(root,0);
    setHight(root);

    for(int i=0;i<n;i++){
        print(i);
    }
    return 0;
}