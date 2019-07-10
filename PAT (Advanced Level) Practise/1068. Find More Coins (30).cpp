#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int n, m;
int a[maxn], dp[110];
bool choice[maxn][110], flag[maxn];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        for (int v = m; v >= a[i]; v--) {
            if (dp[v - a[i]] + a[i] >= dp[v]) {
                choice[i][v] = true;
                dp[v] = dp[v - a[i]] + a[i];
            } else {
                choice[i][v] = false;
                dp[v] = dp[v];
            }
        }
    }
    if (dp[m] != m) {
        printf("No Solution");
        return 0;
    }
    int k = n, cnt = 0;
    while (k) {
        if (choice[k][m]) {
            flag[k] = true;
            m -= a[k];
            cnt++;
        } else {
            flag[k] = false;
        }
        k--;
    }
    for (int i = n; i >= 1; i--) {
        if (flag[i]) {
            printf("%d", a[i]);
            cnt--;
            if (cnt)
                printf(" ");
        }
    }
    return 0;
}
