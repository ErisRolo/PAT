/**
* 分析：模板题，前序中序转后序，一定要十分熟练才行！
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50010;

int n;
int pre[maxn], in[maxn];
vector<int> post;

struct Node {
    int data;
    int lchild, rchild;
} node[maxn];

int create(int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return -1;
    int root = preL;
    node[root].data=pre[root];
    int k;
    for(int i = inL; i <= inR; i++) {
        if(in[i] == pre[preL]) {
            k = i;
            break;
        }
    }
    int numLeft = k - inL;
    node[root].lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    node[root].rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postorder(int root) {
    if(root == -1)
        return;
    postorder(node[root].lchild);
    postorder(node[root].rchild);
    post.push_back(node[root].data);
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    int root = create(0, n - 1, 0, n - 1);
    postorder(root);
    printf("%d", post[0]);
    return 0;
}
