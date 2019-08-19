/**
* 分析：第一标尺cost仍为距离，第二标尺为点权的最短路径问题
*       最短路径最后一题，35分钟AC，就是注意debug时候打的log记得删。。。
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int inf = 1000000000;

int n, k, st, ed;
int g[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                min = d[j];
                u = j;
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

int num = 0, dist = 0;
int maxhappy = 0, maxavghappy = 0;
int h[maxn];
vector<int> path, temppath;
void DFS(int v) {
    if(v == st) {
        temppath.push_back(v);
        num++; //最短路径数+1
        int happy = 0, avghappy = 0;
        for(int i = temppath.size() - 1; i > 0; i--) { //计算最短路径
            int id = temppath[i], nextid = temppath[i - 1];
            dist += g[id][nextid];
        }
        for(int i = temppath.size() - 1; i >= 0; i--) { //计算点权
            int id = temppath[i];
            happy += h[id];
        }
        avghappy = happy / (temppath.size() - 1);
        if(happy > maxhappy) {
            maxhappy = happy;
            maxavghappy = avghappy;
            path = temppath;
        } else if(happy == maxhappy && avghappy > maxavghappy) {
            maxavghappy = avghappy;
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
    int cnt = 0, hp, cost;
    char c[4], a[4], b[4];
    string s, u, v;
    map<string, int> id;
    map<int, string> city;
    scanf("%d %d %s", &n, &k, c);
    s = c;
    id[s] = cnt;
    city[cnt] = s;
    cnt++;
    st = id[s]; //起点：0
    for(int i = 0; i < n - 1; i++) {
        scanf("%s %d", c, &hp);
        s = c;
        if(s != "ROM") {
            id[s] = cnt;
            city[cnt] = s;
            cnt++;
        } else {
            id[s] = n - 1;
            city[n - 1] = s;
        }
        h[id[s]] = hp;
    }
    ed = id["ROM"]; //终点：n-1
    for(int i = 0; i < k; i++) {
        scanf("%s %s %d", a, b, &cost);
        u = a, v = b;
        g[id[a]][id[b]] = g[id[b]][id[a]] = cost;
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d %d %d\n", num, dist / num, maxhappy, maxavghappy);
    for(int i = path.size() - 1; i >= 0; i--) {
        printf("%s", city[path[i]].c_str());
        if(i != 0)
            printf("->");
    }
    return 0;
}
