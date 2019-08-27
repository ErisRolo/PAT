/**
* 分析：中缀表达式，中序遍历解决，可以明确不会出现只有左孩子的结点
*       规律是有孩子结点的非根结点（无论是两个孩子都有还是只有右孩子），遍历完成后在左右加上括号
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;

int n, root;
bool isRoot[maxn];
vector<string> ans;

struct Node {
    string data;
    int lchild, rchild;
} node[maxn];

void inOrder(int root) {
    if(root == -1)
        return;
    if(isRoot[root] == false && node[root].rchild != -1) { //如果不是根结点且有孩子（右孩子）
        ans.push_back("(");
        inOrder(node[root].lchild);
        ans.push_back(node[root].data);
        inOrder(node[root].rchild);
        ans.push_back(")");
    } else {
        inOrder(node[root].lchild);
        ans.push_back(node[root].data);
        inOrder(node[root].rchild);
    }
}

int main() {
    fill(isRoot, isRoot + maxn, true);
    string s;
    int l, r;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s >> l >> r;
        node[i].data = s;
        node[i].lchild = l;
        node[i].rchild = r;
        if(l != -1)
            isRoot[l] = false;
        if(r != -1)
            isRoot[r] = false;
    }
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] == true) {
            root = i;
            break;
        }
    }
    inOrder(root);
    for(auto s : ans)
        cout << s;
    return 0;
}
