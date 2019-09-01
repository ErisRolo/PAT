/**
* 分析：注意在线处理，否则容易TLE
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;

int n, m, a, b, k;
vector<int> g[maxn];
bool flag;
bool vis[maxn];


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(m--) {
        flag = true;
        fill(vis, vis + maxn, false);
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            scanf("%d", &a);
            if(vis[a] == false) {
                vis[a] = true;
                for(auto b : g[a])
                    vis[b] = true;
            } else
                flag = false;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
