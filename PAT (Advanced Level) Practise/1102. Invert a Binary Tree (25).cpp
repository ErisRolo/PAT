/**
* 分析：反转二叉树并进行层次遍历和中序遍历
*       用了不到半个小时AC，仍然用的建树的方法
*       看了下柳神的做法，虽然她没有建树但是这次代码量和我差不多，说明一直用建树的方法是可行的
*       多加练习不断熟练提高编码速度即可
*       说一下这道题，因为题目给的是结点编号，所以用静态实现比较方便
*       反转就是输入左右子树的时候交换，根结点是没有被指向过的结点
*       这道题的坑点在于输入的时候要吸收换行符，注意这个细节学会这个技巧
**/

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 11;

int n, root, cnt1 = 0, cnt2 = 0;
char a, b;

struct Node {
    int lchild;
    int rchild;
    int flag; //用来标记找出根结点，默认应该是为0，不行手动赋值为0
} node[maxn];

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(temp != -1) {
            printf("%d", temp);
            cnt1++;
            if(cnt1 < n)
                printf(" ");
        }
        if(node[temp].lchild != -1)
            q.push(node[temp].lchild);
        if(node[temp].rchild != -1)
            q.push(node[temp].rchild);
    }
}

void inOrder(int root) {
    if(root == -1)
        return;
    inOrder(node[root].lchild);
    printf("%d", root);
    cnt2++;
    if(cnt2 < n)
        printf(" ");
    inOrder(node[root].rchild);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("\n%c %c", &a, &b);
        if(a == '-')
            node[i].rchild = -1;
        else {
            node[i].rchild = a - '0';
            node[node[i].rchild].flag = 1;
        }
        if(b == '-')
            node[i].lchild = -1;
        else {
            node[i].lchild = b - '0';
            node[node[i].lchild].flag = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(node[i].flag == 0) {
            root = i;
            break;
        }
    }
    BFS(root);
    printf("\n");
    inOrder(root);
    return 0;
}
