/**
* 分析：BST和BFS，简单题
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, x, lowest = 0;
int d[maxn];
int ln[maxn];

struct Node {
    int data, lchild, rchild;
    int level;
} node[maxn];

int root = -1, idx = 0;
void insert(int &root, int x) {
    if(root == -1) {
        node[idx].data = x;
        node[idx].lchild = node[idx].rchild = -1;
        root = idx++;
        return;
    }
    if(x <= node[root].data)
        insert(node[root].lchild, x);
    else
        insert(node[root].rchild, x);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    node[root].level = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        int lv = node[front].level;
        ln[lv]++;
        int l = node[front].lchild;
        int r = node[front].rchild;
        if(l != -1) {
            node[l].level = lv + 1;
            if(node[l].level > lowest)
                lowest = node[l].level;
            q.push(l);
        }
        if(r != -1) {
            node[r].level = lv + 1;
            if(node[r].level > lowest)
                lowest = node[r].level;
            q.push(r);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(root, x);
    }
    BFS(root);
    printf("%d + %d = %d", ln[lowest], ln[lowest - 1], ln[lowest] + ln[lowest - 1]);
    return 0;
}
