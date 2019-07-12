#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} node, *Tree;

Tree Create(Tree root, int x) {

    if(root == NULL) {
        root = new node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        return root;
    }
    if(x <= root->data)
        root->lchild = Create(root->lchild, x);
    else
        root->rchild = Create(root->rchild, x);
    return root;
}

int maxdepth = -1;
vector<int>v(1000);

void dfs(Tree root, int h) {
    if(root == NULL)
        return ;
    maxdepth = max(h, maxdepth);
    v[h]++;
    dfs(root->lchild, h + 1);
    dfs(root->rchild, h + 1);
    return ;
}

int main() {
    int n, x;
    Tree root = NULL;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        root = Create(root, x);
    }
    dfs(root, 0);
    //cout<<maxdepth<<endl;
    cout << v[maxdepth] << " + " << v[maxdepth - 1] << " = " << v[maxdepth] + v[maxdepth - 1];
}
