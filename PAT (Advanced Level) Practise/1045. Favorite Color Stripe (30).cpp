#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int order[maxn], a[maxn], dp[maxn], n, m, l;

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    fill(order, order + maxn, -1);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        order[x] = i;
    }
    scanf("%d", &l);
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        int x;
        scanf("%d", &x);
        if (order[x] == -1)
            continue;
        a[cnt++] = order[x];
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    int k = 0;
    for (int i = 0; i < cnt; i++) {
        if (dp[i] > dp[k])
            k = i;
    }
    printf("%d", dp[k]);
    return 0;
}
