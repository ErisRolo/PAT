#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;

int n, root;
bool isRoot[maxn];

struct Node {
    string data;
    int lchild, rchild;
} node[maxn];

string ans;
void postOrder(int root) {
    if (root == -1)
        return;
    if (node[root].lchild != -1 && node[root].rchild != -1) {
        ans += "(";
        postOrder(node[root].lchild);
        postOrder(node[root].rchild);
        ans += node[root].data + ")";
        return;
    }
    if (node[root].lchild == -1 && node[root].rchild != -1) {
        ans += "(" + node[root].data;
        postOrder(node[root].rchild);
        ans += ")";
        return;
    }
    if (node[root].lchild == -1 && node[root].rchild == -1) {
        ans += "(" + node[root].data + ")";
        return;
    }
}

int main() {
    fill(isRoot, isRoot + maxn, true);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> node[i].data;
        scanf("%d%d", &node[i].lchild, &node[i].rchild);
        isRoot[node[i].lchild] = false;
        isRoot[node[i].rchild] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }
    postOrder(root);
    cout << ans << endl;
    return 0;
}