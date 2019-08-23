/**
* 分析：相当于用两次不用的Dijkstra，虽然代码量多但都是复制粘贴，实际很快就搞定了
*       唯一的坑点在于没读懂题目里的one-way什么意思，后来得知是单行道，但其实这个点没设扣分
*       我扣的3分是因为计算mint时可能会重复计算，累加多次，所以每次计算前清零，其实每次计算的值是一样的
*       或者干脆拿出DFS单独算，这种小的点要注意，有时候很可能占更多的分值，一定要仔细
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int inf = 10000000;

int n, m, st, ed;
int g[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];

int t[maxn][maxn];
int dt[maxn];
bool vist[maxn];
vector<int> pret[maxn];


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

int dis;
int mintime = inf;
vector<int> path, temppath;
void DFS(int v) {
    if(v == st) {
        temppath.push_back(v);
        int time = 0, tempdis = 0;
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i - 1];
            tempdis += g[id][nextid];
            time += t[id][nextid];
        }
        if(time < mintime) {
            dis = tempdis;
            mintime = time;
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

void Dijkstrat(int s) {
    fill(dt, dt + maxn, inf);
    dt[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vist[j] == false && dt[j] < min) {
                u = j;
                min = dt[j];
            }
        }
        if(u == -1)
            return;
        vist[u] = true;
        for(int v = 0; v < n; v++) {
            if(vist[v] == false && t[u][v] != inf) {
                if(dt[u] + t[u][v] < dt[v]) {
                    dt[v] = dt[u] + t[u][v];
                    pret[v].clear();
                    pret[v].push_back(u);
                } else if(dt[u] + t[u][v] == dt[v]) {
                    pret[v].push_back(u);
                }
            }
        }
    }
}

int mint = 0;
int minnum = inf;
vector<int> patht, temppatht;
void DFST(int v) {
    if(v == st) {
        temppatht.push_back(v);
        int num = temppatht.size();
        if(num < minnum) {
            mint = 0; //每次清零
            for(int i = temppatht.size() - 1; i > 0; i--) {
                int id = temppatht[i], nextid = temppatht[i - 1];
                mint += t[id][nextid];
            }
            minnum = num;
            patht = temppatht;
        }
        temppatht.pop_back();
        return;
    }
    temppatht.push_back(v);
    for(int i = 0; i < pret[v].size(); i++)
        DFST(pret[v][i]);
    temppatht.pop_back();
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    fill(t[0], t[0] + maxn * maxn, inf);
    int v1, v2, one, len, tim;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d%d%d", &v1, &v2, &one, &len, &tim);
        //if(one==1) {
        //	g[v1][v2]=len;
        //	t[v1][v2]=tim;
        //} else {
        g[v1][v2] = g[v2][v1] = len;
        t[v1][v2] = t[v2][v1] = tim;
        //}
    }
    scanf("%d%d", &st, &ed);
    Dijkstra(st);
    DFS(ed);
    Dijkstrat(st);
    DFST(ed);
    if(path != patht) {
        printf("Distance = %d: ", dis);
        for(int i = path.size() - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if(i != 0)
                printf(" -> ");
            else
                printf("\n");
        }
        printf("Time = %d: ", mint);
        for(int i = patht.size() - 1; i >= 0; i--) {
            printf("%d", patht[i]);
            if(i != 0)
                printf(" -> ");
            else
                printf("\n");
        }
    } else {
        printf("Distance = %d; Time = %d: ", dis, mint);
        for(int i = path.size() - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if(i != 0)
                printf(" -> ");
            else
                printf("\n");
        }
    }
    return 0;
}
