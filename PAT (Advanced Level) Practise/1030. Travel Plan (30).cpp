/**
* 分析：最短路径模板题，这题很重要！两种模板都要学会！！这道题一定要多看几遍！！！
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 100000000;

int n, m, st, ed;
int mincost = inf;
int g[maxn][maxn], cost[maxn][maxn]; //两个边权
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path, temppath;

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
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
    if(v == st) {
        temppath.push_back(v);
        int tempcost = 0;
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i];
            int nextid = temppath[i - 1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost) {
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    temppath.pop_back();
}

int main() {
    int a, b, dis, cos;
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    fill(g[0], g[0] + maxn * maxn, inf);
    fill(cost[0], cost[0] + maxn * maxn, inf);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &dis, &cos);
        g[a][b] = g[b][a] = dis;
        cost[a][b] = cost[b][a] = cos;
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", d[ed], mincost);
    return 0;
}
