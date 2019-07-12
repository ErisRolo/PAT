#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;

int G[maxn][maxn], degree[maxn];
bool vis[maxn];
int n, m;

void DFS(int v) {
    vis[v] = true;
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && G[v][i])
            DFS(i);
    }
}

int Calblock() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i])
            DFS(i), cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x][y] = G[y][x] = 1;
        degree[x]++, degree[y]++;
    }
    int blocks = Calblock();
    int even = 0, odd = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d", degree[i]);
        if(i != n)
            printf(" ");
        if(degree[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("\n");
    if(blocks == 1 && even == n)
        printf("Eulerian\n");
    else if(blocks == 1 && odd == 2)
        printf("Semi-Eulerian\n");
    else
        printf("Non-Eulerian\n");
    return 0;
}
