/**
* 分析：用的是普通的建树的做法，看上去代码量多，其实两个DFS一模一样直接复制的，注意下下标和那个&&就可以了
*       DFS是模仿的图的路径遍历，先获取根结点到两个所求点的两条路径，然后从上往下遍历，找第一组不相等的点，则其父结点为所求
*       如果遍历完还没找到，那么路径较短的那一条的最后一个结点为所求，其实就是较高的那一个是正确的
*       简单说下其他做法，一种是记录每个结点的父结点，用父结点递推获得路径，然后大致同上，注意下标就可，优势在于建树的时候可以记录，不用DFS
*       除了BST那种特殊的树可根据性质解题，最简便的做法是LCA算法，主要思想是若ab在当前子树两侧，则当前子树根结点为所求
*       若ab在根结点左侧，则往左子树递归，若ab在根结点右侧，则往右子树递归，若ab在当前子树两侧，返回当前子树根结点即可
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int m, n, a, b, anc, root;
int pre[maxn], in[maxn];
unordered_set<int> st;

struct Node {
    int data, lchild, rchild;
} node[maxn];

int create(int prel, int prer, int inl, int inr) {
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    int k;
    for(k = inl; k <= inr; k++) {
        if(in[k] == pre[prel])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr);
    return root;
}

vector<int> path, pa, pb;
void DFSA(int root, int a) {
    if(root == -1)
        return;
    if(node[root].data == a) {
        path.push_back(node[root].data);
        pa = path;
        path.pop_back();
        return;
    }
    path.push_back(node[root].data);
    DFSA(node[root].lchild, a);
    DFSA(node[root].rchild, a);
    path.pop_back();
}
void DFSB(int root, int b) {
    if(root == -1)
        return;
    if(node[root].data == b) {
        path.push_back(node[root].data);
        pb = path;
        path.pop_back();
        return;
    }
    path.push_back(node[root].data);
    DFSB(node[root].lchild, b);
    DFSB(node[root].rchild, b);
    path.pop_back();
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        if(st.find(in[i]) == st.end())
            st.insert(in[i]);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    root = create(0, n - 1, 0, n - 1);
    while(m--) {
        scanf("%d%d", &a, &b);
        if(st.find(a) != st.end() && st.find(b) != st.end()) {
            DFSA(root, a), DFSB(root, b);
            int i;
            for(i = 0; i < pa.size() && i < pb.size(); i++) { //注意这里是用的&&，因为是从上往下遍历，不是1143那种从下往上找
                if(pa[i] != pb[i]) {
                    anc = pa[i - 1];
                    break;
                }
            }
            if(i == pa.size())
                anc = pa[pa.size() - 1];
            if(i == pb.size())
                anc = pb[pb.size() - 1];
            if(anc != a && anc != b)
                printf("LCA of %d and %d is %d.\n", a, b, anc);
            else
                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
        } else {
            if(st.find(a) == st.end() && st.find(b) != st.end())
                printf("ERROR: %d is not found.\n", a);
            if(st.find(a) != st.end() && st.find(b) == st.end())
                printf("ERROR: %d is not found.\n", b);
            if(st.find(a) == st.end() && st.find(b) == st.end())
                printf("ERROR: %d and %d are not found.\n", a, b);
        }
    }
    return 0;
}
