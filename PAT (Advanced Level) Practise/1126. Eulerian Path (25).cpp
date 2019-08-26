/**
* 分析：欧拉回路一定是连通图，单独判断这一点
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;

int n, m;
int g[maxn][maxn];
int degree[maxn];
bool vis[maxn];

void DFS(int u) {
    vis[u] = true;
    for(int v = 1; v <= n; v++) {
        if(g[u][v] == 1 && vis[v] == false) {
            DFS(v);
        }
    }
}

int num = 0;
void DFSTrave() {
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            DFS(i);
            num++;
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
        degree[a]++, degree[b]++;
    }
    int even = 0, odd = 0;
    for(int i = 1; i <= n; i++) {
        if(degree[i] % 2 == 0)
            even++;
        else
            odd++;
        printf("%d", degree[i]);
        if(i != n)
            printf(" ");
        else
            printf("\n");
    }
    DFSTrave();
    if(num == 1 && even == n)
        printf("Eulerian\n");
    else if(num == 1 && even == n - 2 && odd == 2)
        printf("Semi-Eulerian\n");
    else
        printf("Non-Eulerian\n");
    return 0;
}
