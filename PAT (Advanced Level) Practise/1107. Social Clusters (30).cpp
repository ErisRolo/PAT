/**
* 分析：并查集，有点难理解，不要弄混父亲结点和根结点，合并的时候是根结点
*       模板固定，真正需要自己思考编写的是并查集的建立部分
*       再多刷几道题理解一下吧
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, k, t, cnt = 0;
int father[maxn];
int isRoot[maxn];
int hobby[maxn];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = 0;
    }
}

int findFather(int a) {
    int b = a;
    while(a != father[a]) {
        a = father[a];
    }
    //路径压缩
    while(b != father[b]) {
        int c = b;
        father[b] = a;
        b = father[c];
    }
    return a;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        father[fb] = fa;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            if(hobby[t] == 0)
                hobby[t] = i; //令第一个对兴趣t感兴趣的人i为兴趣t的集合的根结点
            Union(i, hobby[t]);
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    sort(isRoot + 1, isRoot + 1 + n, cmp);
    for(int i = 1; i <= cnt; i++) {
        if(i < cnt)
            printf("%d ", isRoot[i]);
        else
            printf("%d", isRoot[i]);
    }
    return 0;
}
