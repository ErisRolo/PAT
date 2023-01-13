/**
 * 分析：太丑陋了，没写过这么丑陋的代码
 **/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int g[maxn][maxn] = {0};
bool f[maxn];

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    int k, t, res;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &t);
        vector<int> v(t);
        fill(f, f + maxn, false);
        for (int j = 0; j < t; j++) {
            scanf("%d", &v[j]);
            f[v[j]] = true;
        }
        bool f1 = true, f2 = true;
        for (int j = 0; j < t; j++) {
            for (int l = j + 1; l < t; l++) {
                if (g[v[j]][v[l]] == 0) {
                    f1 = false;
                    break;
                }
            }
            if (!f1)
                break;
        }
        for (int l = 1; l <= n; l++) {
            if (!f[l]) {
                bool temp = true;
                for (auto it = v.begin(); it != v.end(); it++) {
                    if (l != *it && g[l][*it] == 0) {
                        temp = false;
                        break;
                    }
                }
                if (temp) {
                    f2 = false;
                    res = l;
                    break;
                }
            }
        }
        if (!f1)
            printf("Area %d needs help.\n", i);
        else if (!f2)
            printf("Area %d may invite more people, such as %d.\n", i, res);
        else
            printf("Area %d is OK.\n", i);
    }
    system("pause");
    return 0;
}