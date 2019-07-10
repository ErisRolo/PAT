#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;

int dp[maxn][maxn];

int main() {
    char s[maxn];
    while(fgets(s, maxn, stdin)) {
        memset(dp, 0, sizeof(dp));
        int n = strlen(s);
        int maxl = 0;
        for(int i = n - 1; i >= 0; i--) //注意顺序
            for(int j = i; j < n; j++)
                if(s[i] == s[j] && (j - i + 1 < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    maxl = max(maxl, j - i + 1);
                }
        printf("%d\n", maxl);
    }
    return 0;
}
