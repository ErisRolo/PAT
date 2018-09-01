/**
* 分析：所有最短路径题都可以套模板，关键是读懂题意
*       这道题将时间代替距离作为边权，也作为第一标尺
*       第二标尺有两个，一个是带去的自行车数，一个是带回的自行车数
*       还有就是读入点权时的数据处理，直接减去cmax/2，通过正负判断是带走还是带去
*       Dijkstra永远固定，但是要注意下标
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;

int cmax, n, sp, m;
int numpath = 0, minneed = inf, minremain = inf;
int g[maxn][maxn]; //边权即时间
int d[maxn]; //最短距离
int weight[maxn]; //点权即车数
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path, temppath;

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 0; i <= n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j <= n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v <= n; v++) {
            if(vis[v] == false && g[u][v] != inf) {
                if(d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + g[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if(v == 0) {
        temppath.push_back(v);
        int need = 0, remain = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(weight[id] > 0) {
                remain += weight[id];
            } else {
                if(remain > abs(weight[id])) {
                    remain -= abs(weight[id]);
                } else {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minneed) {
            minneed = need;
            minremain = remain;
            path = temppath;
        } else if(need == minneed && remain < minremain) {
            minremain = remain;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    temppath.pop_back();
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    int bike;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &bike);
        weight[i] = bike;
        weight[i] -= cmax / 2;
    }
    int a, b, time;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &time);
        g[a][b] = g[b][a] = time;
    }
    Dijkstra(0);
    DFS(sp);
    printf("%d ", minneed);
    for(int i = path.size() - 1; i > 0; i--)
        printf("%d->", path[i]);
    printf("%d ", path[0]);
    printf("%d", minremain);
    return 0;
}
