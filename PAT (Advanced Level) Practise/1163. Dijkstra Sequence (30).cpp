#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int inf = 1000000000;

int n, m, k, st;
int g[maxn][maxn];
vector<int> v;
int d[maxn];
bool vis[maxn];

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, min = inf;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (vis[v] == false && g[u][v] != inf) {
                if (d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                }
            }
        }
    }
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    int a, b, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        g[a][b] = g[b][a] = t;
    }
    scanf("%d", &k);
    while (k--) {
        bool flag = true;
        v.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t);
            if (i == 1) {
                st = t;
                Dijkstra(st);
            } else {
                v.push_back(t);
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            if (d[v[i]] < d[v[i - 1]]) {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}