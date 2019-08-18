/**
* 分析：先用基本DFS计算连通块数
*       再用简单修改的DFS计算每个顶点能达到的最大深度，为此设一个全局变量，可以将两个DFS合并成一个
*       坑点在于结点个数上界为10000，如果使用邻接矩阵会有一个点TLE，改成邻接表
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int n, cnt = 0, maxdepth = 0;
vector<int> adj[maxn];
bool vis[maxn];
vector<int> ans;

int depth;
int level[maxn];
void DFS(int u) {
    vis[u] = true;
    for(int v = 0; v < adj[u].size(); v++) {
        if(vis[adj[u][v]] == false) {
            level[adj[u][v]] = level[u] + 1;
            if(level[adj[u][v]] > depth)
                depth = level[adj[u][v]];
            DFS(adj[u][v]);
        }
    }
}

void DFSTrave() {
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            DFS(i);
            cnt++;
        }
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFSTrave(); //先计算连通块个数判断是否为树
    if(cnt == 1) { //如果为树
        for(int i = 1; i <= n; i++) { //DFS每个顶点计算最大层数
            fill(vis, vis + maxn, false);
            depth = 0;
            level[i] = 0; //初始化别忘了 这一步要写在DFS外面
            DFS(i);
            if(depth > maxdepth) {
                maxdepth = depth;
                ans.clear();
                ans.push_back(i);
            } else if(depth == maxdepth) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        for(auto it = ans.begin(); it != ans.end(); it++) {
            printf("%d\n", *it);
        }
    } else {
        printf("Error: %d components\n", cnt);
    }
    return 0;
}











//**
//* 分析：卧槽这道题不会做！！！
//*       一开始感觉需要同时用并查集和图的DFS遍历才能解决，但又觉得25分的题不会出得这么难
//*       然后果断看答案，还真是两个考点都用了。。。
//*       不仅如此，这道题要知道一个结论才能做，还要注意特判和去重
//*       不愧是TOP之前的甲级题，确实很难。。。
//*       但是了解结论后，发现稍作修改，就可以去掉并查集的部分，只需使用两个不同的DFS即可
//*       一个用来计算连通块，一个用来统计根结点
//**/
//
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//const int maxn = 100010;
//
//int n, maxheight = 0;
//bool vis[maxn];
//vector<int> Adj[maxn];
//vector<int> temp;
//vector<int> ans;
//
//void DFS(int v) {
//    vis[v] = true;
//    for(int i = 0; i < Adj[v].size(); i++) {
//        if(vis[Adj[v][i]] == false)
//            DFS(Adj[v][i]);
//    }
//}
//
//void NDFS(int v, int height, int pre) {
//    if(height > maxheight) {
//        temp.clear();
//        temp.push_back(v);
//        maxheight = height;
//    } else if(height == maxheight) {
//        temp.push_back(v);
//    }
//    vis[v] = true;
//    for(int i = 0; i < Adj[v].size(); i++) {
//        if(Adj[v][i] == pre)
//            continue;
//        NDFS(Adj[v][i], height + 1, v);
//    }
//}
//
//int main() {
//    int a, b;
//    scanf("%d", &n);
//    for(int i = 1; i <= n - 1; i++) {
//        scanf("%d%d", &a, &b);
//        Adj[a].push_back(b);
//        Adj[b].push_back(a);
//    }
//    int block = 0;
//    for(int i = 1; i <= n; i++) {
//        if(vis[i] == false) {
//            DFS(i);
//            block++;
//        }
//    }
//    if(block == 1) {
//        fill(vis, vis + maxn, false);
//        NDFS(1, 1, -1);
//        ans = temp;
//        NDFS(ans[0], 1, -1);
//        for(int i = 0; i < temp.size(); i++)
//            ans.push_back(temp[i]);
//        sort(ans.begin(), ans.end());
//        printf("%d\n", ans[0]);
//        for(int i = 1; i < ans.size(); i++) {
//            if(ans[i] != ans[i - 1])
//                printf("%d\n", ans[i]);
//        }
//    } else {
//        printf("Error: %d components", block);
//    }
//    return 0;
//}
