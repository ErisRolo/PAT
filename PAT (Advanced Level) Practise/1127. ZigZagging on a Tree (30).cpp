/**
* 分析：中序后序建树，层序遍历交替输出
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int n;
int in[maxn], post[maxn];
vector<int> lv[maxn];

struct Node {
    int data, lchild, rchild;
    int level;
} node[maxn];

int create(int inl, int inr, int postl, int postr) {
    if(postl > postr)
        return -1;
    int root = postr;
    node[root].data = post[postr];
    int k;
    for(k = inl; k <= inr; k++) {
        if(in[k] == post[postr])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(inl, k - 1, postl, postl + numleft - 1);
    node[root].rchild = create(k + 1, inr, postl + numleft, postr - 1);
    return root;
}

int lvn;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    node[root].level = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        lvn = node[front].level; //记录最大层数
        lv[node[front].level].push_back(front);
        if(node[front].lchild != -1) {
            q.push(node[front].lchild);
            node[node[front].lchild].level = node[front].level + 1;
        }
        if(node[front].rchild != -1) {
            q.push(node[front].rchild);
            node[node[front].rchild].level = node[front].level + 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    int root = create(0, n - 1, 0, n - 1);
    BFS(root);
    int num = 0;
    for(int i = 0; i <= lvn; i++) {
        if(i % 2 != 0) {
            for(int j = 0; j < lv[i].size(); j++) {
                printf("%d", node[lv[i][j]].data);
                num++;
                if(num != n)
                    printf(" ");
            }
        } else {
            for(int j = lv[i].size() - 1; j >= 0; j--) {
                printf("%d", node[lv[i][j]].data);
                num++;
                if(num != n)
                    printf(" ");
            }
        }
    }
    return 0;
}
