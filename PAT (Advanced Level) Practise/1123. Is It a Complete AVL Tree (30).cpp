/**
* 分析：判断一棵AVL是不是完全二叉树，要求输出层序遍历
*       AVL部分直接写模板即可
*       判断完全二叉树，则根据层序遍历，第一个叶子结点后出现的结点都是叶子结点，否则就不是完全二叉树
**/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 30;

int n, data, root = -1;

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
            } else if (getBalanceFactor(node[root].lchild) == -1) {
                L(node[root].lchild);
                R(root);
            }
        }
    } else  {
        insert(node[root].rchild, x);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(node[root].rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(node[root].rchild) == 1) {
                R(node[root].rchild);
                L(root);
            }
        }
    }
}

bool isleaf(int root) {
    if(2 * (node[root].lchild + 1) > n)
        return true;
    else
        return false;
}

int cnt = 0;
bool haschild, iscompelete = true;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    if(node[root].lchild != -1 || node[root].rchild != -1)
        haschild = true;
    else
        haschild = false;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        cnt++;
        if(cnt < n)
            printf("%d ", node[temp].data);
        else
            printf("%d\n", node[temp].data);
        if(node[temp].lchild != -1) {
            if(haschild == false)
                iscompelete = false;
            q.push(node[temp].lchild);
        } else {
            haschild = false;
        }
        if(node[temp].rchild != -1) {
            if(haschild == false)
                iscompelete = false;
            q.push(node[temp].rchild);
        } else {
            haschild = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(root, data);
    }
    BFS(root);
    if(iscompelete)
        printf("YES");
    else
        printf("NO");
    return 0;
}
