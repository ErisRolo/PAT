/**
* 分析：写了太长时间了，仿照中序递归建树的写法写的，但是递归边界不一样，具体处理不一样
*       唯一相同的就是划分子区域差不多，但也要修改
*       判断是否唯一就是判断子树结点数目是否为2，或者说该结点是否只有1个孩子
*       这题虽然自己A了，但还是多看看别人的做法
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int n;
int pre[maxn], post[maxn];
bool isonly = true;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int create(int prel, int prer, int postl, int postr) {
    //cout<<"prel="<<prel<<" prer="<<prer<<" postl="<<postl<<" postr="<<postr<<endl;
    int root = prel;
    node[root].data = pre[prel];
    //cout<<"root="<<root<<" node[root]="<<node[root].data<<endl;
    if(prel == prer || postl == postr) {
        node[root].lchild = node[root].rchild = -1;
        return root;
    }
    int k;
    for(k = postl; k <= postr - 1; k++) {
        if(post[k] == pre[prel + 1])
            break;
    }
    //cout<<"k="<<k<<endl;
    int numleft = k - postl + 1;
    int numright = postr - 1 - k;
    if(numleft < 0 || numright < 0)
        return -1;
    if(numleft == 2 || numright == 2)
        isonly = false;
    //cout<<"numleft="<<numleft<<" numright="<<numright<<endl;
    node[root].lchild = create(prel + 1, prel + numleft, postl, postl + numleft - 1);
    node[root].rchild = create(prel + numleft + 1, prer, postl + numleft, postr - 1);
    return root;
}

int num = 0;
void inOrder(int root) {
    //cout<<"inOrder root="<<root<<endl;
    if(root == -1)
        return;
    inOrder(node[root].lchild);
    printf("%d", node[root].data);
    num++;
    if(num != n)
        printf(" ");
    else
        printf("\n");
    inOrder(node[root].rchild);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    int root = create(0, n - 1, 0, n - 1);
    //cout<<"main root="<<root<<endl;
    if(n == 2)
        isonly = false; //特判
    if(isonly)
        printf("Yes\n");
    else
        printf("No\n");
    inOrder(root);
    return 0;
}
