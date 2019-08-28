/**
* 分析：点覆盖，set和pair的使用，对STL的各种技巧一定要熟悉
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 10010;

int n, m, k;
vector<int> adj[maxn];
set<pair<int, int> > st;

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &k);
    int q, u;
    while(k--) {
        scanf("%d", &q);
        st.clear();
        for(int i = 0; i < q; i++) {
            scanf("%d", &u);
            for(int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                st.insert({u, v});
                st.insert({v, u});
            }
        }
        if(st.size() == 2 * m)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
