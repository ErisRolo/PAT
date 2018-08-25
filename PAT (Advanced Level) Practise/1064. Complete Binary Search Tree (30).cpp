/**
* 分析：建一棵完美二叉搜索树，要求熟悉CBT和BST的性质
*       总结下性质记住即可
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, CBT[maxn], data[maxn], index = 0;

void inOrder(int root) {
    if(root > n)
        return;
    inOrder(2 * root);
    CBT[root] = data[index++];
    inOrder(2 * root + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n);
    inOrder(1);
    for(int i = 1; i <= n - 1; i++)
        printf("%d ", CBT[i]);
    printf("%d", CBT[n]);
    return 0;
}
