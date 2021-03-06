/**
* 分析：读懂题意，模拟栈，Push即前序遍历，Pop即中序遍历，本质是前序中序转后序
*       这题我仍然用建树的方法处理，不过采用了静态实现，感觉还是动态实现好理解
*       这道题主要应该学习对模拟栈的字符串处理，如何读取数据，其他的都是基本操作
**/

#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 31;

int n;
int temp, pren = 0, inn = 0, count = 0;
char str[5];
stack<int> st;
int pre[maxn], in[maxn];

struct Node {
    int data;
    int lchild;
    int rchild;
} node[maxn];

int create(int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return -1;
    int root = preL;
    node[root].data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;
    node[root].lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    node[root].rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postOrder(int root) {
    if(root == -1)
        return;
    postOrder(node[root].lchild);
    postOrder(node[root].rchild);
    printf("%d", node[root].data);
    count++;
    if(count < n)
        printf(" ");
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            scanf("%d", &temp);
            st.push(temp);
            pre[pren++] = temp;
        }
        if(strcmp(str, "Pop") == 0) {
            temp = st.top();
            st.pop();
            in[inn++] = temp;
        }
    }
    int root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}
