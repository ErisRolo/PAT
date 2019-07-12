#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;

int n;
int pre[maxn], post[maxn];
vector<int> in;
bool flag = true;

struct Node {
    int data;
    int lchild, rchild;
} node[maxn];

void getIn(int preL, int preR, int postL, int postR) {
    if(preL == preR) {
        in.push_back(pre[preL]);
        return;
    }
    if (pre[preL] == post[postR]) {
        int i = preL + 1;
        while (i <= preR && pre[i] != post[postR - 1])
            i++;
        if (i - preL > 1)
            getIn(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
        else
            flag = false;
        in.push_back(post[postR]);
        getIn(i, preR, postL + (i - preL - 1), postR - 1);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    getIn(0, n - 1, 0, n - 1);
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    for(int i = 0; i < in.size() - 1; i++) {
        printf("%d ", in[i]);
    }
    printf("%d\n", in[in.size() - 1]);
    return 0;
}
