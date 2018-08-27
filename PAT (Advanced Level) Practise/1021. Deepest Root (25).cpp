/**
* 分析：卧槽这道题不会做！！！
*       一开始感觉需要同时用并查集和图的DFS遍历才能解决，但又觉得25分的题不会出得这么难
*       然后果断看答案，还真是两个考点都用了。。。
*       不仅如此，这道题要知道一个结论才能做，还要注意特判和去重
*       不愧是TOP之前的甲级题，确实很难。。。
*       但是了解结论后，发现稍作修改，就可以去掉并查集的部分，只需使用两个不同的DFS即可
*       一个用来计算连通块，一个用来统计根结点
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int n, maxheight = 0;
bool vis[maxn];
vector<int> Adj[maxn];
vector<int> temp;
vector<int> ans;

void DFS(int v) {
    vis[v] = true;
    for(int i = 0; i < Adj[v].size(); i++) {
        if(vis[Adj[v][i]] == false)
            DFS(Adj[v][i]);
    }
}

void NDFS(int v, int height, int pre) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(v);
        maxheight = height;
    } else if(height == maxheight) {
        temp.push_back(v);
    }
    vis[v] = true;
    for(int i = 0; i < Adj[v].size(); i++) {
        if(Adj[v][i] == pre)
            continue;
        NDFS(Adj[v][i], height + 1, v);
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &a, &b);
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int block = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            DFS(i);
            block++;
        }
    }
    if(block == 1) {
        fill(vis, vis + maxn, false);
        NDFS(1, 1, -1);
        ans = temp;
        NDFS(ans[0], 1, -1);
        for(int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] != ans[i - 1])
                printf("%d\n", ans[i]);
        }
    } else {
        printf("Error: %d components", block);
    }
    return 0;
}
