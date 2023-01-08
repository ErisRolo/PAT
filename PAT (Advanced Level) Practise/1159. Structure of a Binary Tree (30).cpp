#include <bits/stdc++.h>
using namespace std;

const int maxn = 31;
int n, m, root;
int post[maxn], in[maxn];
string s;
unordered_map<int, int> id;

struct Node {
    int data, lchild, rchild;
    int parent;
    int level;
} node[maxn];

int create(int postl, int postr, int inl, int inr, int parent, int level) {
    if (postl > postr)
        return -1;
    int root = postr;
    node[root].data = post[postr];
    node[root].parent = parent;
    node[root].level = level;
    int k;
    for (k = inl; k <= inr; k++) {
        if (in[k] == post[postr])
            break;
    }
    int numleft = k - inl;
    node[root].lchild = create(postl, postl + numleft - 1, inl, k - 1, root, level + 1);
    node[root].rchild = create(postl + numleft, postr - 1, k + 1, inr, root, level + 1);
    id[node[root].data] = root;
    return root;
}

bool isfull;
void isFull(int root) {
    int l = node[root].lchild, r = node[root].rchild;
    if ((l == -1 && r != -1) || (l != -1 && r == -1))
        isfull = false;
    if (root == -1)
        return;
    isFull(l);
    isFull(r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    root = create(0, n - 1, 0, n - 1, -1, 0);
    scanf("%d", &m);
    getchar();
    while (m--) {
        getline(cin, s);
        if (s.find("root") != -1) {  // A is the root
            string ts;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    ts += s[i];
                else
                    break;
            }
            int temp = stoi(ts);
            if (temp == node[root].data)
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("siblings") != -1) {
            string as, bs;
            int i;
            for (i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    as += s[i];
                else
                    break;
            }
            for (; i < s.size(); i++) {
                if (isdigit(s[i]))
                    bs += s[i];
            }
            int a = stoi(as), b = stoi(bs);
            if (node[id[a]].parent == node[id[b]].parent)
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("parent") != -1) {
            string as, bs;
            int i;
            for (i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    as += s[i];
                else
                    break;
            }
            for (; i < s.size(); i++) {
                if (isdigit(s[i]))
                    bs += s[i];
            }
            int a = stoi(as), b = stoi(bs);
            if (node[id[b]].parent == id[a])
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("left") != -1) {
            string as, bs;
            int i;
            for (i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    as += s[i];
                else
                    break;
            }
            for (; i < s.size(); i++) {
                if (isdigit(s[i]))
                    bs += s[i];
            }
            int a = stoi(as), b = stoi(bs);
            if (node[id[b]].lchild == id[a])
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("right") != -1) {
            string as, bs;
            int i;
            for (i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    as += s[i];
                else
                    break;
            }
            for (; i < s.size(); i++) {
                if (isdigit(s[i]))
                    bs += s[i];
            }
            int a = stoi(as), b = stoi(bs);
            if (node[id[b]].rchild == id[a])
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("level") != -1) {
            string as, bs;
            int i;
            for (i = 0; i < s.size(); i++) {
                if (s[i] != ' ')
                    as += s[i];
                else
                    break;
            }
            for (; i < s.size(); i++) {
                if (isdigit(s[i]))
                    bs += s[i];
            }
            int a = stoi(as), b = stoi(bs);
            if (node[id[a]].level == node[id[b]].level)
                printf("Yes\n");
            else
                printf("No\n");
        } else if (s.find("full") != -1) {
            isfull = true;
            isFull(root);
            if (isfull)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}