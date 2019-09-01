/**
* 分析：划分区域是在后序序列中找先序序列根结点后面那一个点，这个点以左（包括这个点）为左子树，以右为右子树
*       注意计算左子树结点数目numleft时与中序建树不同，直接在循环里自增
*       判断是否唯一就是判断子树结点数目是否为2，或者说该结点是否只有1个孩子，建每棵树前利用区间确定子树结点数目进行判断
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
    if(prer - prel == 1 || postr - postl == 1) //  if(numleft==2||numright==2)  numleft=prer-prel+1  numright=postr-postl+1
        isonly = false;
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    int k, numleft = 0; //注意这里计算左子树结点数目
    for(k = postl; k < postr; k++) {
        numleft++;
        if(post[k] == pre[prel + 1])
            break;
    }
    //int numleft=k-postl+1;
    node[root].lchild = create(prel + 1, prel + numleft, postl, k);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, postr - 1);
    return root;
}

int num = 0;
void inOrder(int root) {
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
    if(isonly)
        printf("Yes\n");
    else
        printf("No\n");
    inOrder(root);
    return 0;
}
