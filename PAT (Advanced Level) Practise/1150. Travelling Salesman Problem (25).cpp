/**
* 分析：旅行商环路，和判断欧拉回路类似，写的时候注意遍历的是图中的所有点还是路径上的点
*      首先判断是否为旅行商环路，要满足三点：起点终点相同，图连通（连续两点是否可达），访问图中所有的点
*      再判断是否为简单环路，即路径上除了起点出现两次外，其余每个结点是否只出现一次
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, m, q, k;
int path[maxn];
int g[maxn][maxn];
bool ists, issimple;
int h[maxn];

int main() {
    int a, b, t, dis;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &dis);
        g[a][b] = g[b][a] = dis;
    }
    int mindis = 1000000000, mini;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        dis = 0;
        ists = true, issimple = true;
        fill(h, h + maxn, 0);
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &path[j]);
            h[path[j]]++;
        }
        for(int j = 1; j < k; j++) {
            a = path[j], b = path[j - 1];
            if(g[a][b] != 0)
                dis += g[a][b];
            else {
                dis = -1; //统计长度顺便判断是否连通
                ists = false;
                break;
            }
        }
        for(int j = 1; j <= n; j++) { //判断是否遍历图中所有点
            if(h[j] == 0) {
                ists = false;
                break;
            }
        }
        if(path[0] != path[k - 1]) //判断起点终点是否相同
            ists = false;
        if(h[path[0]] != 2) //判断起点是否只出现两次
            issimple = false;
        for(int j = 1; j < k - 1; j++) { //判断路径上的点是否只出现一次
            t = path[j];
            if(h[t] != 1) {
                issimple = false;
                break;
            }
        }
        if(dis != -1)
            printf("Path %d: %d ", i, dis);
        else
            printf("Path %d: NA ", i);
        if(ists) {
            if(issimple)
                printf("(TS simple cycle)\n");
            else
                printf("(TS cycle)\n");
        } else
            printf("(Not a TS cycle)\n");
        if(dis < mindis && dis != -1 && ists) {
            mindis = dis;
            mini = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", mini, mindis);
    return 0;
}
