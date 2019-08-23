/**
* 分析：注意不能输入字符而应该是字符串，因为数字可能是两位
*      艹错得太傻逼了，因为这么一点，白白扣了9分，不然也直接A了
*      另外判断写的很复杂，其实BFS的话，有更简单的做法
*      遇到第一个只有左孩子或者没有孩子结点的结点之后，后面遍历的一定全是叶子结点，否则不是CBT
*      除此之外单独特判是否存在没有左孩子但有右孩子的情况，也不是CBT
*      这么想好像和原来差不多，就是不用加层数了。。。
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;

int n, root, ans;
bool isRoot[maxn];

struct Node {
    int lchild, rchild;
} node[maxn];

bool BFS(int root) {
    bool flag = false;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans = front; //记录最后一个结点
        int l = node[front].lchild;
        int r = node[front].rchild;
        if(flag) { //这之后只要有不是叶子结点的结点那么这棵树就不是CBT
            if(l != -1 || r != -1)
                return false;
        }
        if((l != -1 && r == -1) || (l == -1 && r == -1)) //遇到第一个只有左孩子或者没有孩子结点的结点
            flag = true;
        if(l == -1 && r != -1)
            return false;
        if(l != -1)
            q.push(l);
        if(r != -1)
            q.push(r);
    }
    return true;
}

int main() {
    string l, r; //两位数的话不止一个字符
    scanf("%d", &n);
    getchar();
    fill(isRoot, isRoot + n, true);
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        if(l != "-") {
            int lc = stoi(l);
            node[i].lchild = lc;
            isRoot[lc] = false;
        } else
            node[i].lchild = -1;
        if(r != "-") {
            int rc = stoi(r);
            node[i].rchild = rc;
            isRoot[rc] = false;
        } else
            node[i].rchild = -1;
    }
    for(int i = 0; i < n; i++) {
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    if(BFS(root))
        printf("YES %d", ans);
    else
        printf("NO %d", root);
    return 0;
}














//int n,root,ans;
//int last=0;
//
//struct Node {
//	int lchild,rchild;
//	int level;
//} node[maxn];
//
//bool BFS(int root) {
//	int num=0;
//	bool noleaves=false;
//	queue<int> q;
//	q.push(root);
//	node[root].level=0;
//	while(!q.empty()) {
//		int front=q.front();
//		q.pop();
//		ans=front; //记录最后一个结点
//		num++;
//		int l=node[front].lchild;
//		int r=node[front].rchild;
//		if(node[front].level!=last) {
//			if(l==-1&&r!=-1) {
//				return false;
//			}
//			if(l==-1&&r==-1) {
//				noleaves=true;
//			}
//			if(noleaves) {
//				if(l!=-1||r!=-1)
//					return false;
//			}
//		} else {
//			if(l!=-1||r!=-1) {
//				return false;
//			}
//		}
//		if(l!=-1) {
//			node[l].level=node[front].level+1;
//			q.push(l);
//		}
//		if(r!=-1) {
//			node[r].level=node[front].level+1;
//			q.push(r);
//		}
//	}
//	return true;
//}
//
//bool isRoot[maxn];
//
//int main() {
//	string l,r; //两位数的话不止一个字符
//	scanf("%d",&n);
//	getchar();
//	fill(isRoot,isRoot+n,true);
//	for(int i=0; i<n; i++) {
//		cin>>l>>r;
//		if(l!="-") {
//			int lc=stoi(l);
//			node[i].lchild=lc;
//			isRoot[lc]=false;
//		} else
//			node[i].lchild=-1;
//		if(r!="-") {
//			int rc=stoi(r);
//			node[i].rchild=rc;
//			isRoot[rc]=false;
//		} else
//			node[i].rchild=-1;
//	}
//	for(int i=0; i<n; i++) {
//		if(isRoot[i]) {
//			root=i;
//			break;
//		}
//	}
//	int m=n;
//	while(m!=0) {
//		m/=2;
//		last++;
//	}
//	if(BFS(root))
//		printf("YES %d",ans);
//	else
//		printf("NO %d",root);
//	return 0;
//}
