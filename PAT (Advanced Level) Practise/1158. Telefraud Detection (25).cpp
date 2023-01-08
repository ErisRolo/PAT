/**
 * 分析：给不同的人打超过k个短电话，只有不超过20%的人回应，短电话为5min以内的
 * 先判断是不是嫌疑人，然后在通话记录中找有没有另一个嫌疑人，有的话加入团伙
 **/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int k, n, m;
int father[maxn];
int tol[maxn][maxn];
set<int> to[maxn];   //播出的短电话
set<int> tos[maxn];  //播出的电话 统计嫌疑人用
vector<int> sus;     //嫌疑人
vector<int> ans[maxn];

int findRoot(int x) {
    int y = x;
    while (x != father[x])
        x = father[x];
    while (y != father[y]) {
        int z = y;
        y = father[y];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if (ra != rb) {
        if (ra > rb)
            father[ra] = rb;
        else
            father[rb] = ra;
    }
}

int main() {
    int a, b, d;
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &d);
        tol[a][b] += d;
        // if(d<=5)
        // to[a].insert(b);
        tos[a].insert(b);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j = tos[i].begin(); j != tos[i].end(); j++) {
            int a = i, b = *j;
            if (tol[a][b] <= 5)
                to[a].insert(b);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (to[i].size() > k) {
            int cnt = 0;  //计算回应数
            for (auto j : to[i]) {
                if (tos[j].find(i) != tos[j].end())
                    cnt++;
            }
            if (cnt * 1.0 / to[i].size() <= 0.2)
                sus.push_back(i);
        }
    }
    if (sus.size() != 0) {
        // int cnt = 0;  //团伙数
        // for (int i = 0; i < sus.size(); i++) {
        //     int a = sus[i];
        //     if (id[a] == -1) {
        //         g[cnt].mem.insert(a);
        //         g[cnt].first = a;
        //         id[a] = cnt;
        //         cnt++;
        //     }
        //     for (int j = i + 1; j < sus.size(); j++) {
        //         int b = sus[j];
        //         if (tos[a].find(b) != tos[a].end() && tos[b].find(a) != tos[b].end()) {
        //             g[id[a]].mem.insert(b);
        //             id[b] = id[a];
        //         }
        //     }
        // }
        // sort(g, g + cnt, cmp);
        // for (int i = 0; i < cnt; i++) {
        //     int l = 0, len = g[i].mem.size();
        //     for (auto j : g[i].mem) {
        //         printf("%d", j);
        //         l++;
        //         if (l != len)
        //             printf(" ");
        //     }
        //     printf("\n");
        // }
        for (int i = 1; i <= n; i++)
            father[i] = i;
        for (int i = 0; i < sus.size(); i++) {
            for (int j = i + 1; j < sus.size(); j++) {
                int a = sus[i], b = sus[j];
                if (tos[a].find(b) != tos[a].end() && tos[b].find(a) != tos[b].end()) {
                    Union(a, b);
                }
            }
        }
        for (auto i : sus)
            ans[findRoot(i)].push_back(i);
        for (int i = 1; i <= n; i++) {
            if (ans[i].size() != 0) {
                int l = 0, len = ans[i].size();
                for (int j : ans[i]) {
                    printf("%d", j);
                    l++;
                    if (l != len)
                        printf(" ");
                    else
                        printf("\n");
                }
            }
        }
    } else
        printf("None\n");
    return 0;
}