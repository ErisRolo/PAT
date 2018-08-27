/**
* 分析：做题一定要仔细！要注意输出格式！大小写！
*       思路逐渐理解一些了，就是把有关系的结点放到一个集合，找到第一个结点后就不断合并
*       求什么数据，其实就是求根结点的数量，因为一个根结点就是一个集合的标志
*       不要把父亲结点和根结点搞混
**/

#include <cstdio>
const int maxn = 10010;

int father[maxn];
int isRoot[maxn];
bool flag[maxn];

void init() {
    for(int i = 1; i <= maxn; i++)
        father[i] = i;
}

int findRoot(int x) {
    int y = x;
    while(x != father[x])
        x = father[x];
    while(y != father[y]) {
        int z = y;
        y = father[y];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fa = findRoot(a);
    int fb = findRoot(b);
    if(fa != fb)
        father[fa] = fb;
}

int main() {
    init();
    int n, k;
    int id, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &k, &id);
        flag[id] = true;
        for(int j = 0; j < k - 1; j++) {
            scanf("%d", &temp);
            flag[temp] = true;
            Union(id, temp);
        }
    }
    for(int i = 1; i <= maxn; i++) {
        if(flag[i] == true)
            isRoot[findRoot(i)]++;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= maxn; i++) {
        if(flag[i] == true && isRoot[i] != 0) {
            cnt1++;
            cnt2 += isRoot[i];
        }
    }
    printf("%d %d\n", cnt1, cnt2);
    int q, b1, b2;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &b1, &b2);
        if(findRoot(b1) == findRoot(b2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
