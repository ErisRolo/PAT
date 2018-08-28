/**
* 分析：幸好刷题了不然真不知道，不要什么题都往模板上去套
*       PAT也会有许多图论的题，纯粹根据题意和图的性质解题，这种的自由发挥就好
*       比如这道汉密尔顿回路，读懂题意，画图，思考出判断的逻辑即可
*       判断的依据是，回路顶点数等于顶点总数+1，起始点和终点相同
*       除了起始点和终点是同一个顶点出现两次，其余顶点必出现且仅出现一次
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 210;

int n, m, k, t;
int g[maxn][maxn];
int flag = true;
int times[maxn];
vector<int> query;

bool isConnect(int a, int b) {
    if(g[a][b] == 1)
        return true;
    else
        return false;
}

int main() {
    int v1, v2;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    int v;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        flag = true;
        fill(times, times + maxn, 0);
        query.clear();
        scanf("%d", &t);
        for(int j = 0; j < t; j++) {
            scanf("%d", &v);
            times[v]++;
            query.push_back(v);
        }
        if(query.size() != n + 1) {
            flag = false;
        } else if(query[0] == query[query.size() - 1]) {
            for(int q = 1; q < query.size() - 1; q++) {
                if(times[query[q]] > 1) {
                    flag = false;
                    break;
                }
            }
            for(int q = 1; q < query.size(); q++) {
                if(isConnect(query[q - 1], query[q]) == false) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }
        if(flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
