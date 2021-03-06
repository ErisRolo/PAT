/**
* 分析：改成了Dijkstra+DFS的版本嘻嘻嘻，好好看好好琢磨
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;

int n, m, st, ed;
int numpath = 0, maxweight = -1;
int g[maxn][maxn];
int d[maxn],w[maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path,temppath;

void Dijkstra(int s) { //s为起点
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

void DFS(int v) { // v为当前访问结点
    if(v == st) {
        temppath.push_back(v);
        int weight = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            weight += w[id];
        }
        if(weight > maxweight) {
            maxweight = weight;
            path = temppath;
        }
        numpath++;
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    temppath.pop_back();
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    fill(g[0], g[0] + maxn * maxn, inf); //初始化图g
    int c1, c2, l;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        g[c1][c2] = g[c2][c1] = l; //无向图
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d", numpath, maxweight);
    return 0;
}
