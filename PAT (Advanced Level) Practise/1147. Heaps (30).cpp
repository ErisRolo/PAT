/**
* 分析：判断是不是一个堆，是大顶堆还是小顶堆，并输出后序遍历
*       利用完全二叉树的性质和堆的定义判断，后序遍历直接写即可
*       完全二叉树，用数组操作，存储顺序即层次遍历顺序，根结点编号为n，则左2*n，右2*n+1
*       若结点数为n，最后一个有叶子结点的结点编号为n/2
**/

#include <cstdio>
const int maxn = 1010;

int m, n;
int cbt[maxn];
int flag;

void postorder(int index) {
    if(index > n)
        return;
    postorder(index * 2);
    postorder(index * 2 + 1);
    if(index != 1)
        printf("%d ", cbt[index]);
    else
        printf("%d\n", cbt[index]);
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &cbt[j]);
        }
        if(cbt[1] >= cbt[2]) {
            flag = 1;
            for(int k = 1; k <= n / 2; k++) {
                if(cbt[k] < cbt[2 * k] || ( 2 * k + 1 <= n && cbt[k] < cbt[2 * k + 1])) {
                    flag = 0;
                }
            }
        }
        if(cbt[1] <= cbt[2]) {
            flag = -1;
            for(int k = 1; k <= n / 2; k++) {
                if(cbt[k] > cbt[2 * k] || ( 2 * k + 1 <= n && cbt[k] > cbt[2 * k + 1])) {
                    flag = 0;
                }
            }
        }
        if(flag == 1) {
            printf("Max Heap\n");
        } else if(flag == -1) {
            printf("Min Heap\n");
        } else if(flag == 0) {
            printf("Not Heap\n");
        }
        postorder(1);
    }
    return 0;
}
