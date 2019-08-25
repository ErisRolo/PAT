/**
* 分析：完全平衡二叉树，拼手速
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;

int n, d, root = -1;

struct Node {
    int v;
    int lchild, rchild;
    int height;
} node[maxn];

int getHeight(int root) {
    if(root == -1)
        return 0;
    return node[root].height;
}

int getBalanceFactor(int root) {
    return getHeight(node[root].lchild) - getHeight(node[root].rchild);
}

void updateHeight(int root) {
    node[root].height = max(getHeight(node[root].lchild), getHeight(node[root].rchild)) + 1;
}

void L(int &root) {
    int temp = node[root].rchild;
    node[root].rchild = node[temp].lchild;
    node[temp].lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(int &root) {
    int temp = node[root].lchild;
    node[root].lchild = node[temp].rchild;
    node[temp].rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

int idx = 0;
void insert(int &root, int v) {
    if(root == -1) {
        node[idx].v = v;
        node[idx].lchild = node[idx].rchild = -1;
        node[idx].height = 1;
        root = idx++;
        return;
    }
    if(v < node[root].v) {
        insert(node[root].lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(node[root].lchild) == 1) {
                R(root);
            } else if(getBalanceFactor(node[root].lchild) == -1) {
                L(node[root].lchild);
                R(root);
            }
        }
    } else {
        insert(node[root].rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(node[root].rchild) == -1) {
                L(root);
            } else if(getBalanceFactor(node[root].rchild) == 1) {
                R(node[root].rchild);
                L(root);
            }
        }
    }
}

int num = 0;
bool flag = false, isCBT = true;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        printf("%d", node[front].v);
        num++;
        if(num != n)
            printf(" ");
        else
            printf("\n");
        int lc = node[front].lchild;
        int rc = node[front].rchild;
        if(flag == false) {
            if((lc != -1 && rc == -1) || (lc == -1 && rc == -1))
                flag = true;
        } else {
            if(lc != -1 || rc != -1)
                isCBT = false;
        }
        if(lc == -1 && rc != -1)
            isCBT = false;
        if(lc != -1)
            q.push(lc);
        if(rc != -1)
            q.push(rc);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &d);
        insert(root, d);
    }
    BFS(root);
    if(isCBT)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
