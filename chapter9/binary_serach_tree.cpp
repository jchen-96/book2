#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;


//插入节点
void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z;
    z = (Node *) malloc(sizeof(Node));

    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

}

void inorder(Node *u) {
    if (u == NIL) {
        return;
    }
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == NIL) {
        return;
    }
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

//找到以某个节点为根节点的的所有节点的最小值
Node *findMin(Node *node) {
    while (node->left != NIL)
        node = node->left;
    return node;
}



void deleteNode(Node *z){
    Node *y;//要删除的对象
    Node *x;
    if(z->left==NIL||z->right==NIL)
        y=z;
    else{
        y=findMin(z->right);
    }

    if(y->left!=NIL){
        x=y->left;
    }else{
        x=y->right;
    }

    if(x!=NIL){
        x->parent=y->parent;
    }

    if(y->parent==NIL){
        root=x;
    }else{
        if(y==y->parent->left){
            y->parent->left=x;
        }else{
            y->parent->right=x;
        }
    }

    if(y!=z){
        z->key=y->key;
    }

    free(y);


}


Node *find(int k) {
    Node *x = root;
    while (x != NIL && k != x->key) {
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

int main() {
    int n, x;
    string com;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            insert(x);
        } else if (com == "print") {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        } else if(com=="find"){
            cin >> x;
            Node *t = find(x);
            if (t != NIL) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }else{
            cin>>x;
            deleteNode(find(x));
        }
    }
    return 0;
}