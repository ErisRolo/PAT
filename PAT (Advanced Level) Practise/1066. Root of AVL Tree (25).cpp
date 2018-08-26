/**
* 分析：AVL基本操作！背代码！套模板！晴神牛逼！
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 21;

struct Node {
    int data;
    int lchild, rchild;
    int height;
} node[maxn];

int getHeight(int root) {
    if(root == -1)
        return 0;
    else
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

int index = 0;
void insert(int &root, int x) {
    if(root == -1) {
        node[index].data = x;
        node[index].height = 1;
        node[index].lchild = node[index].rchild = -1;
        root = index++;
        return;
    }
    if(x < node[root].data) {
        insert(node[root].lchild, x);
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
        insert(node[root].rchild, x);
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

int main() {
    int n, data, root = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(root, data);
    }
    printf("%d", node[root].data);
    return 0;
}
