#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *lchild, *rchild;
};

//建树
void build(node* &root, int v) {
    if (root == NULL) {
        root = new node();
        root->lchild = root->rchild = NULL;
        root->val = v;
        return;
    } else if(abs(v) <= abs(root->val))
        build(root->lchild, v);
    else
        build(root->rchild, v);
}

//temp记录黑的个数
void DFS(node* root, int temp, int &black) {
    //叶节点
    if(root == NULL) {
        if(black == -1)
            black = temp;
        else if(black != temp)
            black = -2;
        return;
    }
    if(black == -2)
        return;
    if(root->val > 0)
        temp++;
    DFS(root->lchild, temp, black);
    DFS(root->rchild, temp, black);
}

bool BFS(node* root) {
    queue<node*> q;
    q.push(root);
    if(root->val < 0)
        return false;//根结点是红
    while(!q.empty()) {
        node* top = q.front();
        q.pop();
        int black = -1;
        DFS(top, 0, black);
        if(black == -2)
            return false;
        if(top->lchild != NULL) {
            if(top->val < 0 && top->lchild->val < 0)
                return false;
            else
                q.push(top->lchild);
        }
        if(top->rchild != NULL) {
            if(top->val < 0 && top->rchild->val < 0)
                return false;
            else
                q.push(top->rchild);
        }
    }
    return true;
}

int main() {
    int k, n, v;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &n);
        node *root = NULL;
        for(int j = 0; j < n; j++) {
            scanf("%d", &v);
            build(root, v);
        }
        if(BFS(root) == true)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
