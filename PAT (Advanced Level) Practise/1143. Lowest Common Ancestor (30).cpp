/**
* 分析：发现一种建树可以肯定A的做法，就是建树的时候注意下需要递归建树，插入建树会超时
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;

int m, n, x, a, b, root = -1;
int pre[maxn], in[maxn];
unordered_map<int, int> id; //存储结点在数组中的下标
unordered_map<int, bool> mp; //标记结点是否存在

struct Node {
    int data, lchild, rchild;
    int parent, level;
} node[maxn];

int create(int prel, int prer, int inl, int inr, int parent, int level) {
    if(prel > prer)
        return -1;
    int root = prel;
    node[root].data = pre[prel];
    node[root].parent = parent;
    node[root].level = level;
    id[node[root].data] = root;
    int k;
    for(k = inl; k <= inr; k++) {
        if(in[k] == pre[prel])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1, root, level + 1);
    node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr, root, level + 1);
    return root;
}

int LCA(int a, int b) { //参数为结点下标
    if(a == b)
        return a;
    if(node[a].level > node[b].level)
        LCA(node[a].parent, b);
    else
        LCA(a, node[b].parent);
}

int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        pre[i] = in[i] = x;
        mp[x] = true;
    }
    sort(in, in + n);
    root = create(0, n - 1, 0, n - 1, -1, 0);
    while(m--) {
        scanf("%d%d", &a, &b);
        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
            int anc = node[LCA(id[a], id[b])].data;
            if(anc != a && anc != b)
                printf("LCA of %d and %d is %d.\n", a, b, anc);
            else
                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
        } else {
            if(mp.find(a) == mp.end() && mp.find(b) == mp.end())
                printf("ERROR: %d and %d are not found.\n", a, b);
            if(mp.find(a) != mp.end() && mp.find(b) == mp.end())
                printf("ERROR: %d is not found.\n", b);
            if(mp.find(a) == mp.end() && mp.find(b) != mp.end())
                printf("ERROR: %d is not found.\n", a);
        }
    }
    return 0;
}




//**
//* 分析：给BST，找LCA，一开始在输入的时候，选择先判断大小，交换次序输出，结果只有19分
//*       debug发现一开始的写法，总是认为较大的数可能为根结点，是被样例那个只有左孩子的子树误导了，但如果出现只有右孩子的子树就会出错
//*       所以i应该>=a或者<=b，改正后为20分，debug发现结果对了但输出有错，继续改正，得29分
//*       继续dubug发现两个数相同时输出有错，给出一组实用样例 2 8 7 9 4 -3 0 9
//*       注释部分为不加交换输出更简洁的代码
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int m, n, x, a, b;
//bool isswap;
//vector<int> tree;
//map<int, bool> mp;
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        tree.push_back(x);
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            isswap = false;
//            if(a > b) {
//                swap(a, b);
//                isswap = true;
//            }
//            for(auto i : tree) {
////				if((i>=a&&i<=b)||(i<=a&&i>=b)) {
////					if(i==a||i==b) {
////						if(i==a)
////							printf("%d is an ancestor of %d.\n",a,b);
////						else
////							printf("%d is an ancestor of %d.\n",b,a);
////
////					} else
////						printf("LCA of %d and %d is %d.\n",a,b,i);
////				}
//                if(i >= a && i <= b) {
//                    if(i != a && i != b) {
//                        if(isswap)
//                            printf("LCA of %d and %d is ", b, a);
//                        else
//                            printf("LCA of %d and %d is ", a, b);
//                        printf("%d.\n", i);
//                    } else {
//                        if(i == a)
//                            printf("%d is an ancestor of %d.\n", a, b);
//                        else if(i == b)
//                            printf("%d is an ancestor of %d.\n", b, a);
//                    }
//                    break;
//                }
//            }
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            } else if(mp.find(a) == mp.end() && mp.find(b) != mp.end()) {
//                printf("ERROR: %d is not found.\n", a);
//            } else if(mp.find(a) != mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d is not found.\n", b);
//            }
//        }
//    }
//    return 0;
//}




//**
//* 分析：直接建树的普通做法，但其实考点不在于此，这么写很容易TLE
//*       简单说一下思路，就是存储根结点到所求两个结点的路径
//*       无论是存储父节点然后递推求路径，还是DFS（没试过，应该可以，模仿图的temppath path写法）
//*       然后从上往下，找第一组不相等的结点，则两结点的父结点即为所求
//*       用vector超时用数组也超时，但别人拿这段代码提交是能A的，我太难了
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 10001;
//
//int m, n, x, a, b, root = -1;
//map<int, int> id; //存储结点在数组中的下标
//map<int, bool> mp; //标记结点是否存在
//int pa[maxn], pb[maxn];
//
//struct Node {
//    int data, lchild, rchild;
//    int parent;
//} node[maxn];
//
//int idx = 0;
//void insert(int &root, int x, int parent) {
//    if(root == -1) {
//        node[idx].data = x;
//        node[idx].lchild = node[idx].rchild = -1;
//        node[idx].parent = parent;
//        id[x] = idx; //存储结点在数组中的下标
//        root = idx++;
//        return;
//    }
//    if(x < node[root].data)
//        insert(node[root].lchild, x, root);
//    else
//        insert(node[root].rchild, x, root);
//}
//
//int LCA(int a, int b) { //参数为结点下标
//    //vector<int> pa,pb;
//    //pa.push_back(node[a].data),pb.push_back(node[b].data); //路径上存值，不存下标，因为最后返回的是结点值
//    int ca = 1, cb = 1;
//    pa[0] = node[a].data, pb[0] = node[b].data;
//    while(node[a].parent != -1) {
//        a = node[a].parent;
//        //pa.push_back(node[a].data);
//        pa[ca++] = node[a].data;
//    }
//    while(node[b].parent != -1) {
//        b = node[b].parent;
//        //pb.push_back(node[b].data);
//        pb[cb++] = node[b].data;
//    }
//    int i;
////	for(i=0; i<pa.size()||i<pb.size(); i++) { //从上往下找两条路径上第一组不相等的结点，则两结点的父节点即为所求
////		if(pa[pa.size()-1-i]!=pb[pb.size()-i-1]) //注意这个下标的表示
////			return pa[pa.size()-i]; //返回两结点的父节点，即上一个结点
////	}
////	if(i==pa.size())
////		return pa[0];
////	if(i==pb.size())
////		return pb[0];
//    for(i = 0; i < ca || i < cb; i++) {
//        if(pa[ca - 1 - i] != pb[cb - 1 - i])
//            return pa[ca - i];
//    }
//    if(i == ca)
//        return pa[0];
//    if(i == cb)
//        return pb[0];
//}
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        insert(root, x, root); //根结点的父节点为-1
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            int anc = LCA(id[a], id[b]);
//            if(anc != a && anc != b)
//                printf("LCA of %d and %d is %d.\n", a, b, anc);
//            else
//                printf("%d is an ancestor of %d.\n", anc, anc == a ? b : a);
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end())
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            if(mp.find(a) != mp.end() && mp.find(b) == mp.end())
//                printf("ERROR: %d is not found.\n", b);
//            if(mp.find(a) == mp.end() && mp.find(b) != mp.end())
//                printf("ERROR: %d is not found.\n", a);
//        }
//    }
//    return 0;
//}
