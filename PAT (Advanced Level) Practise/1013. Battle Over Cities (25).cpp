/**
* 分析：这道题要学会如何求无向图的连通块数量，最终答案即连通块数量减1
*       因为图的遍历过程中每次总是访问单个连通块，并将访问过的标记为已访问，因此在遍历的过程中计数即可，每DFS一次数量就+1
*       至于如何处理删除一个结点后的遍历，只需将这个结点提前设为已访问即可，或者可以在DFS遍历时，遇到这个结点就直接return
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int n, m, k;
int G[maxn][maxn];
bool vis[maxn];

void DFS(int v) {
    vis[v] = true;
    for(int i = 1; i <= n; i++) {
        if(G[v][i] != 0 && vis[i] == false)
            DFS(i);
    }
}

int main() {
    int c1, c2;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &c1, &c2);
        G[c1][c2] = G[c2][c1] = 1;
    }
    int lost;
    for(int i = 0; i < k; i++) {
        scanf("%d", &lost);
        int block = 0;
        fill(vis, vis + maxn, false);
        vis[lost] = true;
        for(int i = 1; i <= n; i++) {
            if(vis[i] == false) {
                DFS(i);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
