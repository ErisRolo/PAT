/**
* 分析：关键活动，即关键路径问题
*       先用拓扑排序判断是否为DAG，然后用DP求DAG最长路
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int inf = 1000000000;

int n, m;
int g[maxn][maxn];
int order[maxn][maxn];

vector<int> adj[maxn]; //用邻接表存后继结点
int indegree[maxn];
vector<int> topo; //记录拓扑序
bool topoSort() {
    int num = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u); //拓扑序
        num++;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
        adj[u].clear();
    }
    if(num == n)
        return true;
    else
        return false;
}

int dp[maxn]; //dp[i]：从i号顶点出发能到达的最大长度
vector<int> choice[maxn];
int DP(int i) {
    if(dp[i] > 0)
        return dp[i]; //如果dp[i]已经计算得到，直接返回
    for(int j = 1; j <= n; j++) { //遍历i的所有出边
        if(g[i][j] != inf) {
            int temp = dp[j] + g[i][j];
            if(temp > dp[i]) {
                dp[i] = temp;
                choice[i].clear();
                choice[i].push_back(j);
            } else if(temp == dp[i]) {
                choice[i].push_back(j);
            }
        }
    }
    return dp[i];
}

bool vis[maxn];
void DFS(int i) {
    vis[i] = true;
    for(auto j : choice[i]) {
        DFS(j);
    }
}

int main() {
    fill(g[0], g[0] + maxn * maxn, inf);
    int u, v, w;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        order[u][v] = i;
        g[u][v] = w;
        adj[u].push_back(v);
        indegree[v]++;
    }
    if(topoSort()) {
        vector<int> st; //所有路径起点
        int max = -inf;
        for(auto it = topo.rbegin(); it != topo.rend(); it++) { //注意要逆拓扑求DP
            int i = *it;
            if(DP(i) > max) {
                max = DP(i);
                st.clear();
                st.push_back(i);
            } else if(DP(i) == max) {
                st.push_back(i);
            }
        }
        printf("%d\n", max);
        //按题目要求输出每段关键路径
        for(auto nums : st) {
            DFS(nums);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i])
                continue;
            sort(choice[i].begin(), choice[i].end(), [&](int a, int b) { //起点相同 输出与输入时的顺序相反
                return order[i][a] > order[i][b];
            });
            for(auto j : choice[i]) {
                printf("%d->%d\n", i, j);
            }
        }
    } else {
        printf("0\n");
    }
    return 0;
}
