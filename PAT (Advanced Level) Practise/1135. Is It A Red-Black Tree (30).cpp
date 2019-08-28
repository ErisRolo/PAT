/**
* 分析：红黑树，给出的是先序遍历，可以直接插入建树
*       然后判断根结点是否为黑色
*       接着判断每个红色结点是否有孩子结点，有的话是否为黑色
*       最后一个条件是指判断每个结点，从其出发到达的所有叶子结点的路径上经过的黑色结点数目是否相等
*       前两个很容易，最后一个，先写一个递归函数getnum用于获取黑色结点数目，然后用DFS或BFS遍历判断每个结点即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int k, n, d, root = -1;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int idx = 0;
void insert(int &root, int x) {
    if(root == -1) {
        node[idx].data = x;
        node[idx].lchild = node[idx].rchild = -1;
        root = idx++;
        return;
    }
    if(abs(x) < abs(node[root].data)) {
        insert(node[root].lchild, x);
    } else {
        insert(node[root].rchild, x);
    }
}

int getnum(int root) {
    if(root == -1)
        return 0;
    int lnum = getnum(node[root].lchild);
    int rnum = getnum(node[root].rchild);
    if(node[root].data > 0)
        return max(lnum, rnum) + 1;
    else
        return max(lnum, rnum);
}

bool flag;
void DFS(int root) {
    if(root == -1)
        return;
    int l = node[root].lchild, r = node[root].rchild;
    if(node[root].data < 0) { //判断2
        if(l != -1 && node[l].data < 0)
            flag = false;
        if(r != -1 && node[r].data < 0)
            flag = false;
    }
    //判断3
    int lnum = getnum(l), rnum = getnum(r);
    if(lnum != rnum)
        flag = false;
    DFS(l);
    DFS(r);
}

int main() {
    scanf("%d", &k);
    while(k--) {
        root = -1, idx = 0;
        flag = true;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &d);
            insert(root, d);
        }
        //判断1
        if(node[root].data < 0)
            flag = false;
        DFS(root); //DFS过程中进行判断2和判断3
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
